# Makefile for test data
CC = gcc
CFLAGS = -I../../include
SRC = test_data1.txt test_data2.txt test_data3.txt
OBJ = $(SRC:.txt=.o)
TARGET = test_data_ultimate_c_tool

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

clean:
	rm -f $(OBJ) $(TARGET)
