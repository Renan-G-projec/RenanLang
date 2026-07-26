# Opcodes
This is the table of opcodes decided to make the calculator work.

| Instruction       | Binary |
| --------------    | ------ |
| PUSH byte         | 01 nn  |
| ADD               | 02 00  |
| PRINT             | 03 00  |
| PRINT_ASCII bytes | 04 nn  |
| SUB               | 05 00  |
| JMP               | 06 00  |
| JMP_IF_ZERO       | 07 00  |
| HALT              | 64 00  |