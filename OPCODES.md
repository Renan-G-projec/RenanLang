# Opcodes
This is the table of opcodes decided to make the calculator work.

| Instruction             | Binary | Description                                              |
| ----------------------- | ------ | ------------------------------------------------------   |
| PUSH byte               | 01 nn  | Pushes byte to stack                                     |
| ADD                     | 02 00  | Pops 2 bytes and pushes the sum                          |
| PRINT                   | 03 00  | Pop a byte and print it as an integer                    |
| PRINT_ASCII bytes       | 04 nn  | Pops n bytes andd print them as ascii                    |
| SUB                     | 05 00  | Pops 2 bytes and pushes the subtraction                  |
| JMP                     | 06 00  | Jumps to the setted address                              |
| JMP_IF_ZERO             | 07 00  | Pop a byte. If it is zero, jumps to the setted address.  |
| SET_ADDR                | 08 00  | Pops 4 bytes, reads them as big endian and set address.  |
| HALT                    | 64 00  | Stops the program.                                       |