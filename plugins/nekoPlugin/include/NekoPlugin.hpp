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
  void SFW(std::vector<std::string> args);
  void WHY(std::vector<std::string> args);

  std::string PluginName = "Neko Plugin";
  std::string baseUrl = "https://nekos.life/api/v2/";

  std::map<std::string, std::string> EndPoints;
  std::map<std::string, std::string> SFWEndPoints;

  std::map<std::string, Neko> NekoFunctions;
  std::map<std::string, Neko> SFWNekoFunctions;

  std::string GetFromNekoDotLife(std::string Endpoint);

  std::string GetHentaiGif();
  std::string GetPussy();
  std::string GetNekoGif();
  std::string GetNeko();
  std::string GetLesbian();
  std::string GetKumi();
  std::string GetCumsluts();
  std::string GetClassic();
  std::string GetBoobs();
  std::string GetBJ();
  std::string GetAnal();
  std::string GetAnalArts();
  std::string GetYuri();
  std::string GetTrap();
  std::string GetTits();
  std::string GetGirlSoloGif();
  std::string GetGirlSolo();
  std::string GetSmallBoobs();
  std::string GetPussyWankGif();
  std::string GetPussyArt();
  std::string GetKemonomimi();
  std::string GetKitsune();
  std::string GetKeta();
  std::string GetHolo();
  std::string GetHoloEro();
  std::string GetHentai();
  std::string GetFutanari();
  std::string GetFemdom();
  std::string GetFeetGif();
  std::string GetEroFeet();
  std::string GetFeet();
  std::string GetEro();
  std::string GetEroKitsune();
  std::string GetEroNeko();
  std::string GetEroYuri();
  std::string GetCumArts();
  std::string GetBlowJob();
  std::string GetPussyGif();

  std::string GetTickle();
  std::string GetSlap();
  std::string GetPoke();
  std::string GetPat();
  std::string GetMeow();
  std::string GetLizard();
  std::string GetKiss();
  std::string GetHug();
  std::string GetFoxGirl();
  std::string GetFeed();
  std::string GetCuddle();

  std::string GenerateHelpMessage();
  std::string GenerateSFWHelpMessage();
};

extern "C" PluginBase *create() {
  return new NekoPlugin;
}

extern "C" void removePlugin(PluginBase *plugin) {
  delete plugin;
}

#endif
