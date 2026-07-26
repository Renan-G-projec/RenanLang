// Ad Maiorem Dei Gloriam!
#ifndef VIRTUALMACHINE_HPP
#define VIRTUALMACHINE_HPP

#include <cstdint>
#include <stack>

class VirtualMachine {
public:
    void loadBytecode(std::int8_t const* bytecode);
    void init();

private:
    std::int8_t const* mCode;
    std::uint32_t mCurrentAddress;
    std::stack<std::int8_t> mStack;

    std::int8_t mCurrentInstruction[2];
    bool mRunning;
    
    void _fetch();
    void _execute();
};

#endif