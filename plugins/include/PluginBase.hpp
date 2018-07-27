#ifndef _PLUGIN_BASE_HPP_
#define _PLUGIN_BASE_HPP_

#include <map>
#include <string>
#include <vector>

class PluginBase;

/**
 * @brief Typedef for commands function pointers
 *
 * @author Jorge Bravo
 */
typedef void (PluginBase::*cmd)(std::vector<std::string> args);

/**
 * @brief Typedef for command map
 *
 * @author Jorge Bravo
 */
typedef std::map<std::string, cmd> CommandList;

/**
 * @brief Base class for plugins
 *
 * Every plugin needs to use this class as a base
 * and needs to implement every function inside the class
 * with a function PluginBase *create(void) that return an instance of the class
 * and also need a function void removePlugin(PluginBase *plugin) that remove
 * the instance of that class
 *
 * @author Jorge Bravo
 */
class PluginBase {
public:
  PluginBase() = default;
  virtual ~PluginBase() = default;

  /**
   * @brief get the name of the plugin
   *
   * This function gets called when the main
   * needs to get the name of the plugin
   *
   * @return The name of the plugin
   */
  virtual std::string GetName() = 0;

  /**
   * @brief returns the PluginCommandList of the plugin
   *
   * Normally this function gets called when the plugin is
   * loaded in memory so the main create a table of every plugin
   * and its commands
   *
   * @return A CommandList with every command on the plugin
   */
  virtual CommandList GetCommandList() = 0;

  /**
   * @brief Executes the command with the name of CommandName
   *
   * This function gets called when the user executes a command
   * that's implemented on the plugin
   *
   * @param CommandName The name of the command you want to execute, needs to be in PluginCommandList
   * @param args a vector with all the args passed to the command
   */
  virtual void ExecuteCommand(std::string CommandName, std::vector<std::string> args) = 0;
protected:
  /**
   * @brief Command list that holds all the commands of the plugin
   */
  CommandList PluginCommandList;
};

#endif
