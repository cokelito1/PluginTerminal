#ifndef _PING_PLUGING_HPP_
#define _PING_PLUGING_HPP_

#include <utility>
#include <vector>

#include <PluginBase.hpp>

/**
 * @brief this is an example plugin made for cterm
 *
 * This plugin only implements one command thats ping
 * when the command get executed it put pong on the
 * stdout
 *
 * @author Jorge Bravo
 */
class PingPlugin : public PluginBase {
public:
  PingPlugin();
  ~PingPlugin();

  /**
   * @brief Get the name of the plugin
   *
   * @return PluginName that holds the plugin name
   */
  std::string GetName();

  /**
   * @brief Get all plugin commands
   *
   * @return PluginCommandList that holds all the commands of the plugin
   */
  CommandList GetCommandList();

  /**
   * @brief Execute the command with the name of CommandName
   *
   * @param CommandName The name of the command to execute
   * @param args vector with all the args passed to the command
   */
  void ExecuteCommand(std::string CommandName, std::vector<std::string> args);
private:
  /**
   * @brief Insert a command into PluginCommandList
   *
   * @param Command pair which holds the name and a pointer of the command
   */
  void PutCommand(std::pair<std::string, cmd> Command);

  /**
   * @brief Puts pong into stdout
   *
   * @param args arguments to the command
   */
  void ping(std::vector<std::string> args);

  std::string PluginName = "Ping Plugin";
};

/**
 * @brief returns a new instance of the plugin
 *
 * @return A pointer to the created class
 */
extern "C" PluginBase *create() {
  return new PingPlugin;
}

/**
 * @brief delete an instance of the plugin
 *
 * @param plugin pointer to the instance to delete
 */
extern "C" void removePlugin(PluginBase *plugin) {
  delete plugin;
}

#endif
