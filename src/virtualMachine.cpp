// Ad Maiorem Dei Gloriam!
#include "virtualMachine.hpp"

void VirtualMachine::loadBytecode(std::int8_t const* bytecode) {
    this->mCode = bytecode;
}

void VirtualMachine::init() {
    mRunning = true;
    while (mRunning) {
        _fetch();
        _execute();
    }
}

void VirtualMachine::_fetch() {
    mCurrentInstruction[0] = mCode[mCurrentAddress];
    mCurrentInstruction[1] = mCode[mCurrentAddress + 1];
}

void VirtualMachine::_execute() {
    // To implement
}