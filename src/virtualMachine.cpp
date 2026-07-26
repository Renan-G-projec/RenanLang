// Ad Maiorem Dei Gloriam!
#include "virtualMachine.hpp"
#include "opcodeTable.hpp"

Error::Error(const std::string message, std::uint32_t address) : message{message}, address{address} {};

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
    try {
        switch (mCurrentInstruction[0]) {
            case Opcode::PUSH: {
                mStack.push(mCurrentInstruction[1]);
                break;
            }
            case Opcode::ADD: {
                int arg1 = popStack();
                int arg2 = popStack();
                int sum = arg1 + arg2;
                mStack.push(sum);
                break;
            }
            case Opcode::PRINT: {
                int numberToPrint = popStack();
                std::cout << numberToPrint << '\n';
                break;
            }
            case Opcode::HALT: {
                mRunning = false;
                break;
            }
        }
    } catch (Error error) {
        std::cout << "ERROR: at address " << error.address << '\n' << error.message << '\n';
        mRunning = false;
    }
}

std::int8_t VirtualMachine::popStack() {
    if (mStack.size() < 1) throw Error("Empty stack cannot be popped.", mCurrentAddress);
    std::int8_t stackTop = mStack.top();
    mStack.pop();
    return stackTop;
}