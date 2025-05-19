CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC = src/main.c src/string_utils.c src/hash_utils.c
OBJ = $(SRC:.c=.o)
OUT = tool

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OUT) $(OBJ)

.PHONY: all clean
