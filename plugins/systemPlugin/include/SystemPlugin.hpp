#include <PluginBase.hpp>
#include <vector>
#include <iostream>

void System(PluginBase&, std::vector<std::string> args);

class SystemPlugin : public PluginBase {
public:
  SystemPlugin();
  ~SystemPlugin();

  std::string GetName();
  CommandList GetCommandList();

  void ExecuteCommand(std::string CommandName, std::vector<std::string> args);
private:
  std::string PluginName = "System Plugin";

  void PutCommand(std::pair<std::string, cmd> Command);
};

extern "C" PluginBase *create() {
  return new SystemPlugin;
}

extern "C" void removePlugin(PluginBase *plugin) {
  delete plugin;
}
