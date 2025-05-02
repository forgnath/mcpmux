CC = gcc
CFLAGS = -Wall -Wextra -pendantic -std=c99 -g
SRC = src/main.c src/shell_interface.c
TARGET = mcpmux

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)
