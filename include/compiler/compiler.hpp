// Ad Maiorem Dei Gloriam!
#ifndef COMPILER_HPP
#define COMPILER_HPP

#include <string>
#include <sstream>
#include <cstdint>
#include <unordered_map>
#include <queue>

#include "compiler/lexer.hpp"

// Bytecode is an array of 2 bytes
// uint8_t because of endian

class Compiler {
public:
    // Compiles the entire stringstream and pushes the opcode generated to the bytecode recipient
    void compile(std::string& code, std::vector<std::int8_t>& bytecodeRecipient);
    
private:
    Lexer mLexer;
    void compileStream(scanned_code_t& code, std::vector<std::int8_t>& store);

    void expandCode(scanned_code_t& code);
    void compileCode(const scanned_code_t& code, std::vector<std::int8_t>& store);
};

#endif