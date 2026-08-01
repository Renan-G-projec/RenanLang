# Ad Maiorem Dei Gloriam!

# Project
PROJECT := RenanLang

# Compile config
CC := g++
SRC := $(wildcard src/*.cpp src/**/*.cpp)
INCLUDE := include
TARGET := build/RenanLang

# Colors
NO_COLOR := \033[0m
GREEN := \033[1;32m

all: debug

release:
	@echo "Compiling ${PROJECT} on Release..."
	@${CC} ${SRC} -o ${TARGET} -I${INCLUDE} -O3
	@echo -e "${GREEN}Completed!${NO_COLOR}"
	@echo "Usage: ${TARGET} <bytecode-file>"

debug: 
	@echo "Compiling ${PROJECT} on Debug..."
	@${CC} ${SRC} -o ${TARGET} -I${INCLUDE} -O0 -g -Wall -Wextra -Wpedantic -DDEBUG
	@echo -e "${GREEN}Completed!${NO_COLOR}"
	@echo "Usage: ${TARGET} <bytecode-file>"