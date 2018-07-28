#include <PluginBase.hpp>
#include <vector>
#include <map>
#include <dlfcn.h>
#include <iostream>
#include <filesystem>
#include <sstream>

using namespace std;
namespace fs = std::filesystem;

void printHelp(map<string, PluginBase *> commands) {
  for(auto i : commands) {
    cout << "[" << i.second->GetName() << "] " << i.first << std::endl;
  }
}

int main() {
  map<string, PluginBase *> commands;
  map<PluginBase *, void (*)(PluginBase*)> Destructors;

  vector<string> plugins;
  vector<void *> handlers;

  if(fs::exists("./plugins")) {
      for (auto &p : fs::directory_iterator("./plugins")) {
          if (fs::path(p).extension() == ".so") {
              plugins.push_back(p.path().u8string());
          }
      }
  } else {
      std::cout << "Carpeta plugins no encontrada" << std::endl;
  }

  for(auto p : plugins) {
    void *hndl = dlopen(p.c_str(), RTLD_LAZY);
    if(hndl == NULL) {
      cerr << "Aqui" << endl;
      cerr << dlerror() << endl;
      exit(-1);
    }
    handlers.push_back(hndl);

    PluginBase *(*createObj)() = (PluginBase *(*)()) dlsym(hndl, "create");
    if(createObj == NULL) {
      cout << "Error cargando create en " << p.c_str() << " causa " << dlerror() << endl;
      return -1;
    }

    void (*removeObj)(PluginBase*) = (void (*)(PluginBase*)) dlsym(hndl, "removePlugin");
    if(removeObj == NULL) {
      cout << "Error cargando removePlugin en " << p.c_str() << " causa " << dlerror() << endl;
      return -1;
    }

    PluginBase *plugin = createObj();
    Destructors.insert(pair<PluginBase *, void (*)(PluginBase*)>(plugin, removeObj));

    for(auto i : plugin->GetCommandList()) {
      commands.insert(pair<string, PluginBase *>(i.first, plugin));
    }

    cout << plugin->GetName() << " Insertado" << endl;
  }

  bool running = true;
  while(running) {
    string input;
    vector<string> arg;
    cout << ">";
    std::getline(std::cin, input);
    std::istringstream stream(input);
    if(input != "") {
      while (stream >> input)
          arg.push_back(input);

      try {
        if(arg[0] == "help") {
          printHelp(commands);
        } else if(arg[0] == "exit"){
          running = false;
        } else {
          PluginBase *plugin = commands.at(arg[0]);
          plugin->ExecuteCommand(arg[0], arg);
        }
      } catch(const std::out_of_range& oor) {
        cerr << "Comando no encontrado" << endl;
      }
    }
  }

  for(auto i : Destructors) {
    i.second(i.first);
  }

  for(auto i : handlers) {
    dlclose(i);
  }

  return 0;
}
