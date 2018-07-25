#include <BfPlugin.hpp>
#include <string>
#include <iostream>

BfPlugin::BfPlugin() {
  PutCommand(std::pair<std::string, cmd>("bf", (cmd) &BfPlugin::Interpret));
}

BfPlugin::~BfPlugin() { }

std::string BfPlugin::GetName() {
  return PluginName;
}

CommandList BfPlugin::GetCommandList() {
  return PluginCommandList;
}

void BfPlugin::ExecuteCommand(std::string name, std::vector<std::string> args) {
  (this->*PluginCommandList[name])(args);
}

void BfPlugin::PutCommand(std::pair<std::string, cmd> Command) {
  PluginCommandList.insert(Command);
}

void BfPlugin::Interpret(std::vector<std::string> args) {
  std::string code, tmp = "";
  while(std::cin >> tmp) {
    if(tmp == "END") {
      break;
    }
    code.append(tmp);
  }
  interpreter.clearMemory();
  interpreter.setCode(code);
  interpreter.execute();
}
