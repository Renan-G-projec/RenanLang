# Ad Maiorem Dei Gloriam!

# Project
PROJECT := RenanLang

# Compile config
CC := g++
SRC := $(wildcard src/*.cpp)
INCLUDE := include
TARGET := build/RenanLang

MODE := debug
FLAGS := -O0 -g -Wall -Wextra -Wpedantic 

# Colors
NO_COLOR := \033[0m
GREEN := \033[1;32m

all:
	@echo "Compiling ${PROJECT} on ${MODE}..."
	@${CC} ${SRC} -o ${TARGET} -I${INCLUDE} ${FLAGS}
	@echo -e "${GREEN}Completed!${NO_COLOR}"
	@echo "Usage: ${TARGET} <bytecode-file>"