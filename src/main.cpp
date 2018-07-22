#include <PluginBase.hpp>
#include <vector>
#include <map>
#include <dlfcn.h>
#include <iostream>
#include <filesystem>
#include <sstream>

using namespace std;
namespace fs = std::filesystem;

int main() {
  map<string, PluginBase *> commands;

  map<PluginBase *, void (*)(PluginBase*)> Destructors;

  vector<string> plugins;

  for(auto &p : fs::directory_iterator("./plugins")) {
    if(fs::path(p).extension() == ".so") {
      plugins.push_back(p.path().u8string());
    }
  }

  for(auto p : plugins) {
    void *hndl = dlopen(p.c_str(), RTLD_LAZY);
    if(hndl == NULL) {
      cerr << "Aqui" << endl;
      cerr << dlerror() << endl;
      exit(-1);
    }

    PluginBase *(*createObj)() = (PluginBase *(*)()) dlsym(hndl, "create");
    void (*removeObj)(PluginBase*) = (void (*)(PluginBase*)) dlsym(hndl, "removePlugin");
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
    while (stream >> input)
        arg.push_back(input);

    try {
      PluginBase *plugin = commands.at(arg[0]);
      plugin->ExecuteCommand(arg[0], arg);
    } catch(const std::out_of_range& oor) {
      cerr << "Comando no encontrado" << endl;
    }
  }

  for(auto i : Destructors) {
    i.second(i.first);
  }

  return 0;
}
