#ifndef _PLUGIN_BASE_HPP_
#define _PLUGIN_BASE_HPP_

#include <map>
#include <string>
#include <vector>

class PluginBase;

typedef void (PluginBase::*cmd)(std::vector<std::string> args);
typedef std::map<std::string, cmd> CommandList;

class PluginBase {
public:
  PluginBase() = default;
  virtual ~PluginBase() = default;

  virtual std::string GetName() = 0;
  virtual CommandList GetCommandList() = 0;

  virtual void ExecuteCommand(std::string CommandName, std::vector<std::string> args) = 0;
protected:
  CommandList PluginCommandList;
};

#endif
