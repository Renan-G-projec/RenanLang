// Ad Maiorem Dei Gloriam!
#ifndef VIRTUALMACHINE_HPP
#define VIRTUALMACHINE_HPP

#include <cstdint>
#include <stack>
#include <iostream>
#include <vector>

class VirtualMachine {
public:
    void loadBytecode(std::vector<std::int8_t> bytecode);
    void init();

private:
    std::vector<std::int8_t> mCode;
    std::uint32_t mCurrentAddress = 0;
    std::uint32_t mAddressRegister = 0;
    std::stack<std::int8_t> mStack;

    std::int8_t mCurrentInstruction[2];
    bool mRunning;
    
    std::int8_t popStack();
    void _fetch();
    void _execute();
};

#endif