// Ad Maiorem Dei Gloriam!
#ifndef VIRTUALMACHINE_HPP
#define VIRTUALMACHINE_HPP

#include <cstdint>
#include <stack>

class VirtualMachine {
public:
    void loadBytecode(std::uint8_t* const bytecode);
    void init();

private:
    std::uint8_t* const mCode;
    std::uint32_t mCurrentAddress;
    std::stack<std::int8_t> mStack;
    
    void _fetch();
    void _decode();
    void _execute();
};

#endif