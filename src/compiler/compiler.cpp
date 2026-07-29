// Ad Maiorem Dei Gloriam!
#include "compiler/compiler.hpp"
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
    if (verb == "SET_ADDR") return SET_ADDR;
    if (verb == "HALT") return HALT;
    return INVALID_OPCODE;
}

void Compiler::compile(std::string &code, int8_t* bytecodeRecipient) {
    std::uint32_t currentByte = 0;
    std::string currentLineCode;

    scanned_code_t lexedCode;
    bool success = mLexer.tokenize(code, lexedCode);

    compileStream(lexedCode, bytecodeRecipient);

    if (!success) {
        std::cout << "Exiting...\n";
        exit(-1);
        return;
    } else {

    }
}

void Compiler::compileStream(scanned_code_t& scannedCode, std::int8_t store[]) {
    // I passed 2 hours trying to implement this.

    // Need to break up into smaller pieces
    // expandCode();
    // compileCode();
}

bool Compiler::isComment(const std::string& line) {
    return line.find("//") == 0;
}