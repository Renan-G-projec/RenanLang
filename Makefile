# Ad Maiorem Dei Gloriam!

CC := g++
SRC := src/main.cpp
INCLUDE := include
TARGET := build/RenanLang

# Colors
NO_COLOR := \033[0m
GREEN := \033[1;32m

linux:
	@echo "Compiling linux release..."
	@${CC} ${SRC} -o ${TARGET} -I${INCLUDE}
	@echo -e "${GREEN}Completed!${NO_COLOR}"
	@echo "Usage: ${TARGET} <bytecode-file>"