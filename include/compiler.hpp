// Ad Maiorem Dei Gloriam!
#ifndef COMPILER_HPP
#define COMPILER_HPP

#include <string>
#include <sstream>
#include <cstdint>

// Bytecode is an array of 2 bytes
// uint8_t because of endian

class Compiler {
public:
    //Compiles the entire stringstream and pushes the opcode generated to the bytecode recipient
    void compile(std::stringstream& code, std::int8_t bytecodeRecipient[]);

private:
    void compileLine(const std::string& line, std::int8_t store[]);
};

#endif