// Ad Maiorem Dei Gloriam!
#ifndef COMPILER_HPP
#define COMPILER_HPP

#include <sstream>
#include <cstdint>

// Bytecode is an array of 2 bytes
// uint8_t because of endian
typedef std::uint8_t* bytecode_t;

class Compiler {
public:
    //Compiles the entire stringstream and pushes the opcode generated to the bytecode recipient
    void compile(std::stringstream& code, std::uint8_t*& bytecodeRecipient);

private:
    bytecode_t compileLine(const std::string& line);
};

#endif