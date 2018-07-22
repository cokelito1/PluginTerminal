#include <iostream>
#include "PingPlugin.hpp"

void ping(PluginBase& plugin, std::vector<std::string> args) {
  std::cout << "[" << plugin.GetName() << "]: Pong" << std::endl;
}

void exitProgram(PluginBase& plugin, std::vector<std::string> args) {
  std::cout << "[" << plugin.GetName() << "]: Saliendo" << std::endl;
  exit(0);
}

PingPlugin::PingPlugin() : PluginBase(){
  PutCommand(std::pair<std::string, cmd>("ping", &ping));
  PutCommand(std::pair<std::string, cmd>("exit", &exitProgram));
}

PingPlugin::~PingPlugin() { }

std::string PingPlugin::GetName() {
  return PluginName;
}

CommandList PingPlugin::GetCommandList() {
  return PluginCommandList;
}

void PingPlugin::ExecuteCommand(std::string CommandName, std::vector<std::string> args) {
  PluginCommandList[CommandName](*this, args);
}

void PingPlugin::PutCommand(std::pair<std::string, cmd> Command) {
   PluginCommandList.insert(Command);
}
