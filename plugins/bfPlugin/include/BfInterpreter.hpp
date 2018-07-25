#ifndef _BF_INTERPRETER_HPP_
#define _BF_INTERPRETER_HPP_

#include <string>
#include <array>
#include <cstdint>

class BfInterpreter {
public:
  BfInterpreter();
  BfInterpreter(std::string code);
  ~BfInterpreter();

  void translateJumps();
  void setCode(std::string code);
  void execute();
  void clearMemory();
private:
  std::string code;
  std::array<uint8_t, 300000> memory;
  std::array<uint32_t, 300000> jumpTable;

  uint32_t PC;
  uint32_t SP;
};

#endif
