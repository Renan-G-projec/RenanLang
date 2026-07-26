// Ad Maiorem Dei Gloriam!
#ifndef OPCODETABLE_HPP
#define OPCODETABLE_HPP

enum Opcode {
    PUSH = 1,
    ADD,
    PRINT,
    PRINT_ASCII,
    SUB,
    JMP,
    JMP_IF_ZERO,
    HALT = 64,
    INVALID_OPCODE
};

#endif