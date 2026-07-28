// Ad Maiorem Dei Gloriam!
#include "compiler.hpp"
#include <iostream>

#include "opcodeTable.hpp"

Opcode processOpcode(const std::string& verb) {
    if (verb == "PUSH") return PUSH;
    if (verb == "ADD") return ADD;
    if (verb == "PRINT") return PRINT;
    if (verb == "PRINT_ASCII") return PRINT_ASCII;
    if (verb == "SUB") return SUB;
    if (verb == "JMP") return JMP;
    if (verb == "JMP_IF_ZERO") return JMP_IF_ZERO;
    if (verb == "HALT") return HALT;
    return INVALID_OPCODE;
}

void Compiler::compile(std::stringstream &code, int8_t* bytecodeRecipient) {
    std::uint32_t currentByte = 0;
    std::string currentLineCode;

    while (std::getline(code, currentLineCode)) {
        std::int8_t bytecode[2];
        if (isComment(currentLineCode)) continue;
        
        compileLine(currentLineCode, bytecode);
        bytecodeRecipient[currentByte] = bytecode[0];
        bytecodeRecipient[currentByte + 1] = bytecode[1];

        currentByte += 2;
    }
}

void Compiler::compileLine(const std::string& code, std::int8_t store[]) {
    std::stringstream lineStream{code};
    std::string verb;
    std::string arg;

    lineStream >> verb;
    Opcode opcode = processOpcode(verb);
    store[0] = static_cast<std::uint8_t>(opcode);

    if (opcode == Opcode::INVALID_OPCODE) {
        std::cout << "Error: Token " << verb << " does not match any know token. Exiting.\n";
        exit(-1);
    }

    // If the opcode needs an argument, it is processed through this switch
    switch (opcode) {
        case Opcode::PUSH: {
            lineStream >> arg;
            int numericArg = std::stoi(arg);
            store[1] = numericArg;
            break;
        }
        case Opcode::PRINT_ASCII: {
            lineStream >> arg;
            int numericArg = std::stoi(arg);
            store[1] = numericArg;
            break;   
        }
        default: {
            store[1] = 0;
            break;
        }
    }
}

bool Compiler::isComment(const std::string& line) {
    return line.find("//") == 0;
}