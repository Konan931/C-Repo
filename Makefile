CC=gcc
CFLAGS=-Wall -Wextra -g -Iinclude
LDFLAGS=-lpthread -lssl -lcrypto
SRC=$(wildcard src/*.c)
OBJ=$(SRC:.c=.o)
TARGET=ultimate_c_tool

all: $(TARGET)

$(TARGET): main.o $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) main.o $(TARGET)

.PHONY: all clean