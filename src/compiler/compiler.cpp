// Ad Maiorem Dei Gloriam!
#include "compiler/compiler.hpp"
#include <iostream>

#include "opcodeTable.hpp"

bool isBigEndian();

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
    // I passed +2 hours trying to implement this.

    // Need to break up into smaller pieces
    expandCode(scannedCode);
    compileCode(scannedCode, store);
}

void Compiler::expandCode(scanned_code_t& code) {
    std::uint32_t byteoffset = 0;
    std::unordered_map<std::string, std::uint32_t> mCalltable;

    // We map the byte offset and the tables
    for (std::int32_t i = 0; i < code.size(); ++i) {
        std::pair<Token, std::string> token = code[i];
        if (token.first == KEYWORD) {
            byteoffset += 2; // Opcode always become bigger
            auto nextToken = code[i + 1];
            if (nextToken.first == STRING_LITERAL) byteoffset += nextToken.second.size() * 2; // Expands to push ch for each char on the string.
            if (nextToken.first == LABEL_IDENTIFIER) byteoffset += 12; // 8 for 4 push instructions, 2 for SET_ADDR and 2 for JMP/JMP_IF_ZERO
        }
        if (token.first == LABEL) mCalltable[token.second] = byteoffset;
    }

    // Then we copy the array and expands it removing the labels
    scanned_code_t newCode{code};
    code.clear();

    for (auto label : mCalltable) {
        std::cout << "LABEL: " << label.first << "ADDRESS: " << label.second << '\n';
    };
    
    std::uint32_t currentIndex = 0;

    while (currentIndex < newCode.size()) {
        auto rawToken = newCode[currentIndex];
        if (rawToken.first == KEYWORD && processOpcode(rawToken.second) == PUSH) {
            auto nextToken = newCode[currentIndex + 1];

            if (nextToken.first == STRING_LITERAL) {
                for (int i = nextToken.second.size() - 1; i >= 0; --i) {
                    auto ch = nextToken.second[i];
                    code.push_back({KEYWORD, "PUSH"});
                    code.push_back({CHAR_LITERAL, std::string{ch}});
                    code.push_back({SEPARATOR, ";"});
                };
                currentIndex++;
            } else {
                code.push_back(rawToken);
            }
        } else if (rawToken.first == KEYWORD && (processOpcode(rawToken.second) == JMP || processOpcode(rawToken.second) == JMP_IF_ZERO)) {
            auto nextToken = newCode[currentIndex + 1];
            auto labelAddress = mCalltable[nextToken.second];

            std::uint8_t addresses[4];

            for (std::uint8_t i = 0; i < 4; ++i) {
                auto byteOffset = isBigEndian() ? i * 8 : 8 * (i - 3);
                addresses[i] = (labelAddress & (0b11111111UL << byteOffset) >> i);
                code.push_back({KEYWORD, "PUSH"});
                code.push_back({NUM_LITERAL, std::to_string(addresses[i])});
                code.push_back({SEPARATOR, ";"});
            }

            code.push_back({KEYWORD, "SET_ADDR"});
            code.push_back({KEYWORD, rawToken.second});
        } else {
            code.push_back(rawToken);
        }
        currentIndex++;
    }

}

void Compiler::compileCode(const scanned_code_t& code, std::int8_t store[]) {
    std::uint32_t bytecodeIndex = 0;

    for (std::uint32_t i = 0; i < code.size(); ++i) {
        auto token = code[i];
        if (token.first == KEYWORD) {
            auto opcode = processOpcode(token.second);
            store[bytecodeIndex++] = opcode;

            std::uint8_t arg = 0;
            if (opcode == PUSH) {
                if (code[i + 1].first == CHAR_LITERAL) arg = code[i + 1].second[0];
                if (code[i + 1].first == NUM_LITERAL) arg = std::stoi(code[i + 1].second);
            } else if (opcode == PRINT_ASCII) {
                if (code[i + 1].first == CHAR_LITERAL) arg = code[i + 1].second[0];
                if (code[i + 1].first == NUM_LITERAL) arg = std::stoi(code[i + 1].second);
            }
            store[bytecodeIndex++] = arg;
        }
    }
};