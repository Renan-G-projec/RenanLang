// Ad Maiorem Dei Gloriam!
#include "compiler.hpp"
#include <iostream>

void Compiler::compile(std::stringstream &code, uint8_t bytecodeRecipient[]) {
    std::uint32_t currentLine = 0;
    std::string currentLineCode;

    while (std::getline(code, currentLineCode)) {
        bytecodeRecipient[0] = 23;
        currentLine++;
    }

}