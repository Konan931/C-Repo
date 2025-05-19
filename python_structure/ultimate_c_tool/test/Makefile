# Makefile for tests
CC = gcc
CFLAGS = -I../include
SRC = test_string_utils.c test_hash_utils.c test_memory_utils.c test_number_utils.c test_debug_utils.c test_file_utils.c test_thread_utils.c test_data_structures.c
OBJ = $(SRC:.c=.o)
TARGET = test_ultimate_c_tool

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

clean:
	rm -f $(OBJ) $(TARGET)
