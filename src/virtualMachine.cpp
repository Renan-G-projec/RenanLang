// Ad Maiorem Dei Gloriam!
#include "virtualMachine.hpp"
#include "opcodeTable.hpp"

void VirtualMachine::loadBytecode(std::int8_t* bytecode) {
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

    mCurrentAddress += 2;
}

void VirtualMachine::_execute() {
    switch (mCurrentInstruction[0]) {
        case Opcode::PUSH: {
            mStack.push(mCurrentInstruction[1]);
            break;
        }
        case Opcode::ADD: {
            int arg1 = mStack.top();
            mStack.pop();
            int arg2 = mStack.top();
            mStack.pop();
            int sum = arg1 + arg2;
            mStack.push(sum);
            break;
        }
        case Opcode::PRINT: {
            int numberToPrint = mStack.top();
            mStack.pop();
            std::cout << numberToPrint << '\n';
            break;
        }
        case Opcode::HALT: {
            mRunning = false;
            break;
        }
    }
}