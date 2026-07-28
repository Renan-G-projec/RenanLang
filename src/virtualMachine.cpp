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
            if (mStack.size() < 2) {
                std::cout << "Error: At line " << mCurrentAddress << '\n' << "Opcode ADD: Stack Underflow";
                mRunning = false;
                break;
            } 
            int arg1 = popStack();
            int arg2 = popStack();
            int sum = arg1 + arg2;
            mStack.push(sum);
            break;
        }
        case Opcode::PRINT: {
            if (mStack.size() < 1) {
                std::cout << "Error: At line " << mCurrentAddress << '\n' << "Opcode PRINT: Stack Underflow";
                mRunning = false;
                break;
            } 
            int numberToPrint = popStack();
            std::cout << numberToPrint << '\n';
            break;
        }
        case Opcode::PRINT_ASCII: {
            std::uint8_t numChars = mCurrentInstruction[1];
            if (mStack.size() < numChars) {
                std::cout << "Error at line " << mCurrentAddress << '\n' << "Opcode PRINT_ASCII: Stack underflow.";
                mRunning = false;
                break;
            }

            char* string = static_cast<char*>(malloc(numChars + 1));
            for (std::uint8_t i = 0; i < numChars; ++i) {
                string[i] = popStack();
            }
            string[numChars] = '\0';

            std::cout << string;

            free(string);
            break;
        }
        case Opcode::HALT: {
            mRunning = false;
            break;
        }
    }
}

std::int8_t VirtualMachine::popStack() {
    std::int8_t stackTop = mStack.top();
    mStack.pop();
    return stackTop;
}