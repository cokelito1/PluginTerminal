#ifndef _ECHO_PLUGIN_HPP_
#define _ECHO_PLUGIN_HPP_

#include <string>
#include <vector>
#include <PluginBase.hpp>

void echo(PluginBase&, std::vector<std::string> args);

class EchoPlugin : public PluginBase{
public:
  EchoPlugin();
  ~EchoPlugin();

  std::string GetName();
  CommandList GetCommandList();

  void ExecuteCommand(std::string CommandName, std::vector<std::string> args);
private:
  void PutCommand(std::pair<std::string, cmd> Command);

  std::string PluginName = "Echo Plugin";
};

extern "C" PluginBase *create() {
  return new EchoPlugin;
}

extern "C" void removePlugin(PluginBase *plugin) {
  delete plugin;
}

#endif
