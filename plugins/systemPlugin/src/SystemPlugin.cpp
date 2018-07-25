#include <PluginBase.hpp>
#include <SystemPlugin.hpp>

#include <stdlib.h>

void SystemPlugin::System(std::vector<std::string> args) {
  std::string systemCommand = "";
  for(int i=1; i<args.size(); i++) {
    systemCommand.append(args[i]);
    systemCommand.append(" ");
  }

  system(systemCommand.c_str());
}

void SystemPlugin::Shell(std::vector<std::string> args) {
  system("/bin/bash");
}

SystemPlugin::SystemPlugin() : PluginBase() {
  PutCommand(std::pair<std::string, cmd>("system", (cmd)&SystemPlugin::System));
  PutCommand(std::pair<std::string, cmd>("shell", (cmd)&SystemPlugin::Shell));
}

SystemPlugin::~SystemPlugin() { }

std::string SystemPlugin::GetName() {
  return PluginName;
}

CommandList SystemPlugin::GetCommandList() {
  return PluginCommandList;
}

void SystemPlugin::ExecuteCommand(std::string CommandName, std::vector<std::string> args) {
  (this->*PluginCommandList[CommandName])(args);
}

void SystemPlugin::PutCommand(std::pair<std::string, cmd> Command) {
  PluginCommandList.insert(Command);
}
