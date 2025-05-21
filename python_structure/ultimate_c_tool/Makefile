# Makefile for ultimate_c_tool
CC = gcc
CFLAGS = -Iinclude
SRC = src/main.c src/string_utils.c src/hash_utils.c src/memory_utils.c src/number_utils.c src/debug_utils.c src/file_utils.c src/thread_utils.c src/data_structures.c
OBJ = $(SRC:.c=.o)
TARGET = ultimate_c_tool

all: $(TARGET)

$(TARGET): $(OBJ)
    $(CC) $(CFLAGS) -o $@ $^

clean:
    rm -f $(OBJ) $(TARGET)
