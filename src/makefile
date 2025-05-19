# compile with: make all
# clean with: make clean
# This makefile is for a C project that includes multiple source files
# and uses the GCC compiler.
# It compiles the source files into object files and links them into an executable.
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC = src/main.c src/string_utils.c src/hash_utils.c src/memory_utils.c
# Add more source files as needed
# The object files will be generated from the source files
OBJ = $(SRC:.c=.o)
OUT = tool

# The output executable name
all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# clean: Remove the object files and the executable
# This is useful to start fresh
# and ensure that all files are recompiled
# when you run make again
# This is useful for debugging
clean:
	rm -f $(OUT) $(OBJ)

.PHONY: all clean
