#include <NekoPlugin.hpp>
#include <cpr/cpr.h>
#include <json.hpp>
#include <algorithm>
#include <iostream>

using json = nlohmann::json;

void NekoPlugin::NSFW(std::vector<std::string> args) {
  if(args.size() < 2) {
    std::cout << HelpMessage << std::endl;
  } else {
    try {
      std::transform(args[1].begin(), args[1].end(), args[1].begin(), ::tolower);
      Neko nekoFunc = NekoFunctions.at(args[1]);
      std::string url = (this->*nekoFunc)();
      std::string com = "display " + url;
      system(com.c_str());
    } catch(const std::out_of_range &oor) {
      std::cout << HelpMessage << std::endl;
    }
  }
}

std::string NekoPlugin::GetHentaiGif() {
  auto image = cpr::Get(cpr::Url{baseUrl + EndPoints["RandomHentaiGif"]});
  if(image.status_code == 200) {
    auto url = json::parse(image.text);
    return url["url"];
  }

  return "Error";
}

std::string NekoPlugin::GetPussy() {
  auto image = cpr::Get(cpr::Url{baseUrl + EndPoints["Pussy"]});
  if(image.status_code == 200) {
    auto url = json::parse(image.text);
    return url["url"];
  }

  return "Error";
}

std::string NekoPlugin::GetNekoGif() {
  auto image = cpr::Get(cpr::Url{baseUrl + EndPoints["NekoGif"]});
  if(image.status_code == 200) {
    auto url = json::parse(image.text);
    return url["url"];
  }

  return "Error";
}

std::string NekoPlugin::GetNeko() {
  auto image = cpr::Get(cpr::Url{baseUrl + EndPoints["Neko"]});
  if(image.status_code == 200) {
    auto url = json::parse(image.text);
    return url["url"];
  }

  return "Error";
}

std::string NekoPlugin::GetLesbian() {
  auto image = cpr::Get(cpr::Url{baseUrl + EndPoints["Lesbian"]});
  if(image.status_code == 200) {
    auto url = json::parse(image.text);
    return url["url"];
  }

  return "Error";
}

std::string NekoPlugin::GetKumi() {
  auto image = cpr::Get(cpr::Url{baseUrl + EndPoints["Kuni"]});
  if(image.status_code == 200) {
    auto url = json::parse(image.text);
    return url["url"];
  }

  return "Error";
}

std::string NekoPlugin::GetCumsluts() {
  auto image = cpr::Get(cpr::Url{baseUrl + EndPoints["Cumslut"]});
  if(image.status_code == 200) {
    auto url = json::parse(image.text);
    return url["url"];
  }

  return "Error";
}

NekoPlugin::NekoPlugin() : PluginBase() {
  PutCommand(std::pair<std::string, cmd>("nsfw", (void (PluginBase::*)(std::vector<std::string>))&NekoPlugin::NSFW));

  EndPoints["RandomHentaiGif"] = "img/Random_hentai_gif";
  EndPoints["Pussy"] = "img/pussy";
  EndPoints["NekoGif"] = "img/nfsw_neko_gif";
  EndPoints["Neko"] = "img/lewd";
  EndPoints["Lesbian"] = "img/les";
  EndPoints["Kuni"] = "img/kuni";
  EndPoints["Cumsluts"] = "img/cum";

  NekoFunctions["hentaigif"] = &NekoPlugin::GetHentaiGif;
  NekoFunctions["pussy"] = &NekoPlugin::GetPussy;
  NekoFunctions["nekogif"] = &NekoPlugin::GetNekoGif;
  NekoFunctions["neko"] = &NekoPlugin::GetNeko;
  NekoFunctions["lesbian"] = &NekoPlugin::GetLesbian;
  NekoFunctions["kumi"] = &NekoPlugin::GetKumi;
  NekoFunctions["cumsluts"] = &NekoPlugin::GetCumsluts;
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
