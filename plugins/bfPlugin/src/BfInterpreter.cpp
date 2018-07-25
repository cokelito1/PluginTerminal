#include <BfInterpreter.hpp>
#include <iostream>
#include <stack>

BfInterpreter::BfInterpreter() {
  PC = 0;
  SP = 0;
}

BfInterpreter::BfInterpreter(std::string code) : BfInterpreter() {
  this->code = code;
  translateJumps();
}

BfInterpreter::~BfInterpreter() {}

void BfInterpreter::setCode(std::string code) {
  this->code = code;
}

void BfInterpreter::clearMemory() {
  for(int i=0; i<jumpTable.size(); i++) {
    jumpTable[i] = 0;
    memory[i] = 0;
  }
  PC = 0;
  SP = 0;
}

void BfInterpreter::translateJumps() {
  std::stack<uint32_t> OpenBrack;
  int bracketNesting = 0;
  char ins;
  while(PC < code.size()) {
    ins = code[PC];
    if(ins == '[') {
      OpenBrack.push(PC);
      bracketNesting++;
      PC++;
      while(bracketNesting && PC < code.size()) {
        ins = code[PC];
        if(ins == '[') {
          OpenBrack.push(PC);
          bracketNesting++;
        } else if(ins == ']') {
          bracketNesting--;
          jumpTable[PC] = OpenBrack.top();
          jumpTable[OpenBrack.top()] = PC;
          OpenBrack.pop();
        }
        PC++;
      }
      PC--;
    }
    PC++;
  }
  PC = 0;
}

void BfInterpreter::execute() {
  translateJumps();
  char ins;
  while(PC < code.size()) {
    ins = code[PC];
    switch (ins) {
      case '+':
        memory[SP]++;
        break;
      case '-':
        memory[SP]--;
        break;
      case '>':
        SP++;
        break;
      case '<':
        SP--;
        break;
      case '.':
        std::cout.put((char) memory[SP]);
        break;
      case ',':
        memory[SP] = std::cin.get();
        break;
      case '[':
        if(memory[SP] == 0) {
          PC = jumpTable[PC];
        }
        break;
      case ']':
        if(memory[SP] != 0) {
          PC = jumpTable[PC];
        }
        break;
    }
    PC++;
  }
}
