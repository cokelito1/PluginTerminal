#ifndef _CORE_PLUGIN_HPP_
#define _CORE_PLUGIN_HPP_

#include <PluginBase.hpp>
#include <vector>
#include <string>

class NekoPlugin : public PluginBase {
public:
  NekoPlugin();
  ~NekoPlugin();

  std::string GetName();
  CommandList GetCommandList();

  void ExecuteCommand(std::string CommandName, std::vector<std::string> args);
private:
  typedef std::string (NekoPlugin::*Neko)();

  void PutCommand(std::pair<std::string, cmd> Command);
  void NSFW(std::vector<std::string> args);

  std::string PluginName = "Neko Plugin";
  std::string baseUrl = "https://nekos.life/api/v2/";

  std::map<std::string, std::string> EndPoints;
  std::map<std::string, Neko> NekoFunctions;

  std::string GetHentaiGif();
  std::string GetPussy();
  std::string GetNekoGif();
  std::string GetNeko();
  std::string GetLesbian();
  std::string GetKumi();
  std::string GetCumsluts();

  std::string HelpMessage = "NSFW <Option> \nHentaiGif\nPussy\nNekoGif\nNeko\nLesbian\nKumi\nCumslut";
};

extern "C" PluginBase *create() {
  return new NekoPlugin;
}

extern "C" void removePlugin(PluginBase *plugin) {
  delete plugin;
}

#endif
