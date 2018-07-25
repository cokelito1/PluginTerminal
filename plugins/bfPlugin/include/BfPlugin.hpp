#ifndef _BF_PLUGIN_HPP_
#define _BF_PLUGIN_HPP_

#include <PluginBase.hpp>
#include <BfInterpreter.hpp>
#include <string>
#include <vector>

typedef enum {
  BF_ERROR            = 0,
  BF_INCREMENT        = 1,
  BF_DECREMENT        = 2,
  BF_MOVE_LEFT        = 3,
  BF_MOVE_RIGHT       = 4,
  BF_INPUT            = 5,
  BF_OUTPUT           = 6,
  BF_JUMP_IF_ZERO     = 7,
  BF_JUMP_IF_NOT_ZERO = 8,
}BfTypes_t;

class BfPlugin : public PluginBase{
public:
  BfPlugin();
  ~BfPlugin();

  std::string GetName();
  CommandList GetCommandList();

  void ExecuteCommand(std::string name, std::vector<std::string> args);
private:
  void Interpret(std::vector<std::string> args);
  void InterpretJumps();

  void PutCommand(std::pair<std::string, cmd> Command);

  BfInterpreter interpreter;
  std::string PluginName = "Brainfuck Plugin";
};

extern "C" PluginBase *create() {
  return new BfPlugin;
}

extern "C" void removePlugin(PluginBase *plugin) {
  delete plugin;
}

#endif
