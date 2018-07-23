#include <NekoPlugin.hpp>
#include <cpr/cpr.h>
#include <json.hpp>
#include <algorithm>
#include <iostream>

using json = nlohmann::json;

void NekoPlugin::NSFW(std::vector<std::string> args) {
  if(args.size() < 2) {
    std::cout << GenerateHelpMessage() << std::endl;
  } else {
    try {
      std::transform(args[1].begin(), args[1].end(), args[1].begin(), ::tolower);
      Neko nekoFunc = NekoFunctions.at(args[1]);
      std::string url = (this->*nekoFunc)();
      if(url.find("http") != std::string::npos) {
        std::string com = "animate -loop 0 " + url;
        system(com.c_str());
      } else {
        std::cout << url;
      }
    } catch(const std::out_of_range &oor) {
      std::cout << GenerateHelpMessage() << std::endl;
    }
  }
}

void NekoPlugin::SFW(std::vector<std::string> args) {
  if(args.size() < 2) {
    std::cout << GenerateSFWHelpMessage() << std::endl;
  } else {
    try {
      std::transform(args[1].begin(), args[1].end(), args[1].begin(), ::tolower);
      Neko nekoFunc = SFWNekoFunctions.at(args[1]);
      std::string url = (this->*nekoFunc)();
      if(url.find("http") != std::string::npos) {
        std::string com = "animate -loop 0 " + url;
        system(com.c_str());
      } else {
        std::cout << url;
      }
    } catch(const std::out_of_range &oor) {
      std::cout << GenerateSFWHelpMessage() << std::endl;
    }
  }
}

std::string NekoPlugin::GenerateHelpMessage() {
  std::string help = "";
  for(auto i : EndPoints) {
    help.append(i.first + "\n");
  }

  return help;
}

std::string NekoPlugin::GenerateSFWHelpMessage() {
  std::string help = "";
  for(auto i : SFWEndPoints) {
    help.append(i.first + "\n");
  }

  return help;
}

std::string NekoPlugin::GetFromNekoDotLife(std::string Endpoint) {
  auto image = cpr::Get(cpr::Url{baseUrl + Endpoint});
  if(image.status_code == 200) {
    try {
      auto url = json::parse(image.text);
      return url["url"];
    } catch(nlohmann::detail::type_error &error) {
      return "Error parseando json\n";
    }
  }

  return "Error\n";
}

void NekoPlugin::WHY(std::vector<std::string> args) {
  auto why = cpr::Get(cpr::Url{baseUrl + "why"});
  if(why.status_code == 200) {
    try {
      auto whyJson = json::parse(why.text);
      std::cout << whyJson["why"] << std::endl;
    } catch(nlohmann::detail::type_error &error) {
      std::cout << "Error parseando JSON" << std::endl;
    }
  }
}

std::string NekoPlugin::GetHentaiGif() {
  return GetFromNekoDotLife(EndPoints["RandomHentaiGif"]);
}

std::string NekoPlugin::GetPussy() {
  return GetFromNekoDotLife(EndPoints["Pussy"]);
}

std::string NekoPlugin::GetNekoGif() {
  return GetFromNekoDotLife(EndPoints["NekoGif"]);
}

std::string NekoPlugin::GetNeko() {
  return GetFromNekoDotLife(EndPoints["Neko"]);
}

std::string NekoPlugin::GetLesbian() {
  return GetFromNekoDotLife(EndPoints["Lesbian"]);
}

std::string NekoPlugin::GetKumi() {
  return GetFromNekoDotLife(EndPoints["Kuni"]);
}

std::string NekoPlugin::GetCumsluts() {
  return GetFromNekoDotLife(EndPoints["Cumsluts"]);
}

std::string NekoPlugin::GetClassic() {
  return GetFromNekoDotLife(EndPoints["Classic"]);
}

std::string NekoPlugin::GetBoobs() {
  return GetFromNekoDotLife(EndPoints["Boobs"]);
}

std::string NekoPlugin::GetBJ() {
  return GetFromNekoDotLife(EndPoints["BJ"]);
}

std::string NekoPlugin::GetAnal() {
  return GetFromNekoDotLife(EndPoints["Anal"]);
}

std::string NekoPlugin::GetAnalArts() {
  return GetFromNekoDotLife(EndPoints["AnalArts"]);
}

std::string NekoPlugin::GetYuri() {
  return GetFromNekoDotLife(EndPoints["Yuri"]);
}

std::string NekoPlugin::GetTrap() {
  return GetFromNekoDotLife(EndPoints["Trap"]);
}

std::string NekoPlugin::GetTits() {
  return GetFromNekoDotLife(EndPoints["Tits"]);
}

std::string NekoPlugin::GetGirlSoloGif() {
  return GetFromNekoDotLife(EndPoints["GirlSoloGif"]);
}

std::string NekoPlugin::GetGirlSolo() {
  return GetFromNekoDotLife(EndPoints["GirlSolo"]);
}

std::string NekoPlugin::GetSmallBoobs() {
  return GetFromNekoDotLife(EndPoints["SmallBoobs"]);
}

std::string NekoPlugin::GetPussyWankGif() {
  return GetFromNekoDotLife(EndPoints["PussyWankGif"]);
}

std::string NekoPlugin::GetPussyArt() {
  return GetFromNekoDotLife(EndPoints["PussyArt"]);
}

std::string NekoPlugin::GetKemonomimi() {
  return GetFromNekoDotLife(EndPoints["Kemonomimi"]);
}

std::string NekoPlugin::GetKitsune() {
  return GetFromNekoDotLife(EndPoints["Kitsune"]);
}

std::string NekoPlugin::GetKeta() {
  return GetFromNekoDotLife(EndPoints["Keta"]);
}

std::string NekoPlugin::GetHolo() {
  return GetFromNekoDotLife(EndPoints["Holo"]);
}

std::string NekoPlugin::GetHoloEro() {
  return GetFromNekoDotLife(EndPoints["HoloEro"]);
}

std::string NekoPlugin::GetHentai() {
  return GetFromNekoDotLife(EndPoints["Hentai"]);
}

std::string NekoPlugin::GetFutanari() {
  return GetFromNekoDotLife(EndPoints["Futanari"]);
}

std::string NekoPlugin::GetFemdom() {
  return GetFromNekoDotLife(EndPoints["Femdom"]);
}

std::string NekoPlugin::GetFeetGif() {
  return GetFromNekoDotLife(EndPoints["FeetGif"]);
}

std::string NekoPlugin::GetEroFeet() {
  return GetFromNekoDotLife(EndPoints["EroFeet"]);
}

std::string NekoPlugin::GetFeet() {
  return GetFromNekoDotLife(EndPoints["Feet"]);
}

std::string NekoPlugin::GetEro() {
  return GetFromNekoDotLife(EndPoints["Ero"]);
}

std::string NekoPlugin::GetEroKitsune() {
  return GetFromNekoDotLife(EndPoints["EroKitsune"]);
}

std::string NekoPlugin::GetEroNeko() {
  return GetFromNekoDotLife(EndPoints["EroNeko"]);
}

std::string NekoPlugin::GetEroYuri() {
  return GetFromNekoDotLife(EndPoints["EroYuri"]);
}

std::string NekoPlugin::GetCumArts() {
  return GetFromNekoDotLife(EndPoints["CumArts"]);
}

std::string NekoPlugin::GetBlowJob() {
  return GetFromNekoDotLife(EndPoints["BlowJob"]);
}

std::string NekoPlugin::GetPussyGif() {
  return GetFromNekoDotLife(EndPoints["PussyGif"]);
}

std::string NekoPlugin::GetTickle() {
  return GetFromNekoDotLife(SFWEndPoints["Tickle"]);
}

std::string NekoPlugin::GetSlap() {
  return GetFromNekoDotLife(SFWEndPoints["Slap"]);
}

std::string NekoPlugin::GetPoke() {
  return GetFromNekoDotLife(SFWEndPoints["Poke"]);
}

std::string NekoPlugin::GetPat() {
  return GetFromNekoDotLife(SFWEndPoints["Pat"]);
}

std::string NekoPlugin::GetMeow() {
  return GetFromNekoDotLife(SFWEndPoints["Meow"]);
}

std::string NekoPlugin::GetLizard() {
  return GetFromNekoDotLife(SFWEndPoints["Lizard"]);
}

std::string NekoPlugin::GetKiss() {
  return GetFromNekoDotLife(SFWEndPoints["Kiss"]);
}

std::string NekoPlugin::GetHug() {
  return GetFromNekoDotLife(SFWEndPoints["Hug"]);
}

std::string NekoPlugin::GetFoxGirl() {
  return GetFromNekoDotLife(SFWEndPoints["FoxGirl"]);
}

std::string NekoPlugin::GetFeed() {
  return GetFromNekoDotLife(SFWEndPoints["Feed"]);
}

std::string NekoPlugin::GetCuddle() {
  return GetFromNekoDotLife(SFWEndPoints["Cuddle"]);
}

NekoPlugin::NekoPlugin() : PluginBase() {
  PutCommand(std::pair<std::string, cmd>("nsfw", (void (PluginBase::*)(std::vector<std::string>))&NekoPlugin::NSFW));
  PutCommand(std::pair<std::string, cmd>("sfw", (void (PluginBase::*)(std::vector<std::string>))&NekoPlugin::SFW));
  PutCommand(std::pair<std::string, cmd>("why", (void (PluginBase::*)(std::vector<std::string>))&NekoPlugin::WHY));

  EndPoints["RandomHentaiGif"] = "img/Random_hentai_gif";
  EndPoints["Pussy"] = "img/pussy";
  EndPoints["NekoGif"] = "img/nfsw_neko_gif";
  EndPoints["Neko"] = "img/lewd";
  EndPoints["Lesbian"] = "img/les";
  EndPoints["Kuni"] = "img/kuni";
  EndPoints["Cumsluts"] = "img/cum";
  EndPoints["Classic"] = "img/classic";
  EndPoints["Boobs"] = "img/boobs";
  EndPoints["BJ"] = "img/bj";
  EndPoints["Anal"] = "img/anal";
  EndPoints["AnalArts"] = "img/anal_jpg";
  EndPoints["Yuri"] = "img/yuri";
  EndPoints["Trap"] = "img/trap";
  EndPoints["Tits"] = "img/tits";
  EndPoints["GirlSoloGif"] = "img/solog";
  EndPoints["GirlSolo"] = "img/solo";
  EndPoints["SmallBoobs"] = "img/smallboobs";
  EndPoints["PussyWankGif"] = "img/pwankg";
  EndPoints["PussyArt"] = "img/pussy_jpg";
  EndPoints["Kemonomimi"] = "img/lewdkemo";
  EndPoints["Kitsune"] = "img/lewdk";
  EndPoints["Keta"] = "img/keta";
  EndPoints["Holo"] = "img/hololewd";
  EndPoints["HoloEro"] = "img/holoero";
  EndPoints["Hentai"] = "img/hentai";
  EndPoints["Futanari"] = "img/futanari";
  EndPoints["Femdom"] = "img/femdom";
  EndPoints["FeetGif"] = "img/feetg";
  EndPoints["EroFeet"] = "img/erofeet";
  EndPoints["Feet"] = "img/feet";
  EndPoints["Ero"] = "img/ero";
  EndPoints["EroKitsune"] = "img/erok";
  EndPoints["EroKemonomimi"] = "img/erokemo";
  EndPoints["EroNeko"] = "img/eron";
  EndPoints["EroYuri"] = "img/eroyuri";
  EndPoints["CumArts"] = "img/cum_jpg";
  EndPoints["BlowJob"] = "img/blowjob";
  EndPoints["PussyGif"] = "img/pussy";

  SFWEndPoints["Tickle"] = "img/tickle";
  SFWEndPoints["Slap"] = "img/slap";
  SFWEndPoints["Poke"] = "img/poke";
  SFWEndPoints["Pat"] = "img/pat";
  SFWEndPoints["Meow"] = "img/meow";
  SFWEndPoints["Lizard"] = "img/lizard";
  SFWEndPoints["Kiss"] = "img/kiss";
  SFWEndPoints["Hug"] = "img/hug";
  SFWEndPoints["FoxGirl"] = "img/fox_girl";
  SFWEndPoints["Feed"] = "img/feed";
  SFWEndPoints["Cuddle"] = "img/cuddle";

  SFWNekoFunctions["tickle"] = &NekoPlugin::GetTickle;
  SFWNekoFunctions["slap"] = &NekoPlugin::GetSlap;
  SFWNekoFunctions["poke"] = &NekoPlugin::GetPoke;
  SFWNekoFunctions["pat"] = &NekoPlugin::GetPat;
  SFWNekoFunctions["meow"] = &NekoPlugin::GetMeow;
  SFWNekoFunctions["lizard"] = &NekoPlugin::GetLizard;
  SFWNekoFunctions["kiss"] = &NekoPlugin::GetKiss;
  SFWNekoFunctions["hug"] = &NekoPlugin::GetHug;
  SFWNekoFunctions["foxgirl"] = &NekoPlugin::GetFoxGirl;
  SFWNekoFunctions["feed"] = &NekoPlugin::GetFeed;
  SFWNekoFunctions["cuddle"] = &NekoPlugin::GetCuddle;

  NekoFunctions["randomhentaigif"] = &NekoPlugin::GetHentaiGif;
  NekoFunctions["pussy"] = &NekoPlugin::GetPussy;
  NekoFunctions["nekogif"] = &NekoPlugin::GetNekoGif;
  NekoFunctions["neko"] = &NekoPlugin::GetNeko;
  NekoFunctions["lesbian"] = &NekoPlugin::GetLesbian;
  NekoFunctions["kuni"] = &NekoPlugin::GetKumi;
  NekoFunctions["cumsluts"] = &NekoPlugin::GetCumsluts;
  NekoFunctions["classic"] = &NekoPlugin::GetClassic;
  NekoFunctions["boobs"] = &NekoPlugin::GetBoobs;
  NekoFunctions["bj"] = &NekoPlugin::GetBJ;
  NekoFunctions["anal"] = &NekoPlugin::GetAnal;
  NekoFunctions["analarts"] = &NekoPlugin::GetAnalArts;
  NekoFunctions["yuri"] = &NekoPlugin::GetYuri;
  NekoFunctions["trap"] = &NekoPlugin::GetTrap;
  NekoFunctions["tits"] = &NekoPlugin::GetTits;
  NekoFunctions["girlsologif"] = &NekoPlugin::GetGirlSoloGif;
  NekoFunctions["girlsolo"] = &NekoPlugin::GetGirlSolo;
  NekoFunctions["smallboobs"] = &NekoPlugin::GetSmallBoobs;
  NekoFunctions["pussywankgif"] = &NekoPlugin::GetPussyWankGif;
  NekoFunctions["pussyart"] = &NekoPlugin::GetPussyArt;
  NekoFunctions["kemonomimi"] = &NekoPlugin::GetKemonomimi;
  NekoFunctions["kitsune"] = &NekoPlugin::GetKitsune;
  NekoFunctions["keta"] = &NekoPlugin::GetKeta;
  NekoFunctions["holo"] = &NekoPlugin::GetHolo;
  NekoFunctions["holoero"] = &NekoPlugin::GetHoloEro;
  NekoFunctions["hentai"] = &NekoPlugin::GetHentai;
  NekoFunctions["futanari"] = &NekoPlugin::GetFutanari;
  NekoFunctions["femdom"] = &NekoPlugin::GetFemdom;
  NekoFunctions["feetgif"] = &NekoPlugin::GetFeetGif;
  NekoFunctions["erofeet"] = &NekoPlugin::GetEroFeet;
  NekoFunctions["feet"] = &NekoPlugin::GetFeet;
  NekoFunctions["ero"] = &NekoPlugin::GetEro;
  NekoFunctions["erokitsune"] = &NekoPlugin::GetEroKitsune;
  NekoFunctions["eroneko"] = &NekoPlugin::GetEroNeko;
  NekoFunctions["eroyuri"] = &NekoPlugin::GetEroYuri;
  NekoFunctions["cumarts"] = &NekoPlugin::GetCumArts;
  NekoFunctions["blowjob"] = &NekoPlugin::GetBlowJob;
  NekoFunctions["pussygif"] = &NekoPlugin::GetPussyGif;
}

NekoPlugin::~NekoPlugin() {}

CommandList NekoPlugin::GetCommandList() {
  return PluginCommandList;
}

std::string NekoPlugin::GetName() {
  return PluginName;
}

void NekoPlugin::ExecuteCommand(std::string CommandName, std::vector<std::string> args) {
  (this->*PluginCommandList[CommandName])(args);
}

void NekoPlugin::PutCommand(std::pair<std::string, cmd> Command) {
  PluginCommandList.insert(Command);
}
