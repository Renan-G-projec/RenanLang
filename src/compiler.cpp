// Ad Maiorem Dei Gloriam!
#include "compiler.hpp"
#include <iostream>

void Compiler::compile(std::stringstream &code, uint8_t bytecodeRecipient[]) {
    std::uint32_t currentByte = 0;
    std::string currentLineCode;

    while (std::getline(code, currentLineCode)) {
        std::uint8_t bytecode[2];
        compileLine(currentLineCode, bytecode);
        bytecodeRecipient[currentByte] = bytecode[0];
        bytecodeRecipient[currentByte + 1] = bytecode[1];

        currentByte += 2;
    }
}

void Compiler::compileLine(const std::string& code, std::uint8_t store[]) {
    // To implement...
}