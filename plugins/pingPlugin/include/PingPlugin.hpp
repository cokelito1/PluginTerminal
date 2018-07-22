#ifndef _PING_PLUGING_HPP_
#define _PING_PLUGING_HPP_

#include <utility>
#include <vector>

#include <PluginBase.hpp>

void ping(PluginBase&, std::vector<std::string> args);
void exitProgram(PluginBase&, std::vector<std::string> args);

class PingPlugin : public PluginBase {
public:
  PingPlugin();
  ~PingPlugin();

  std::string GetName();
  CommandList GetCommandList();

  void ExecuteCommand(std::string CommandName, std::vector<std::string> args);
private:
  void PutCommand(std::pair<std::string, cmd> Command);

  std::string PluginName = "Ping Plugin";
};

extern "C" PluginBase *create() {
  return new PingPlugin;
}

extern "C" void removePlugin(PluginBase *plugin) {
  delete plugin;
}

#endif
