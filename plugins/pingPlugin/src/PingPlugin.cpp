#include <iostream>
#include "PingPlugin.hpp"

void PingPlugin::ping(std::vector<std::string> args) {
  std::cout << "[" << GetName() << "]: Pong" << std::endl;
}

PingPlugin::PingPlugin() : PluginBase(){
  PutCommand(std::pair<std::string, cmd>("ping", (void (PluginBase::*)(std::vector<std::string>)) &PingPlugin::ping));
}

PingPlugin::~PingPlugin() { }

std::string PingPlugin::GetName() {
  return PluginName;
}

CommandList PingPlugin::GetCommandList() {
  return PluginCommandList;
}

void PingPlugin::ExecuteCommand(std::string CommandName, std::vector<std::string> args) {
  (this->*PluginCommandList[CommandName])(args);
}

void PingPlugin::PutCommand(std::pair<std::string, cmd> Command) {
   PluginCommandList.insert(Command);
}
