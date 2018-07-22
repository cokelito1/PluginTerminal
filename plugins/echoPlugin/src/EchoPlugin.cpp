#include <PluginBase.hpp>
#include <EchoPlugin.hpp>
#include <iostream>

void echo(PluginBase& plugin, std::vector<std::string> args) {
  if(args.size() <= 1){
    std::cerr << "Menos de 1 arg no aceptado" << std::endl;
  } else {
    std::cout << "[" << plugin.GetName() << "] ";
    for(int i = 1; i < args.size(); i++) {
      std::cout << args[i] << " ";
    }
    std::cout << std::endl;
  }
}

EchoPlugin::EchoPlugin() : PluginBase(){
  PutCommand(std::pair<std::string, cmd>("echo", &echo));
}

EchoPlugin::~EchoPlugin() {}

std::string EchoPlugin::GetName() {
  return PluginName;
}

CommandList EchoPlugin::GetCommandList() {
  return PluginCommandList;
}

void EchoPlugin::ExecuteCommand(std::string CommandName, std::vector<std::string> args) {
  PluginCommandList[CommandName](*this, args);
}

void EchoPlugin::PutCommand(std::pair<std::string, cmd> Command) {
  PluginCommandList.insert(Command);
}
