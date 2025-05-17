CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99 -g
SRC = src/main.c src/shell_interface.c src/log.c src/utils.c src/command.c src/world.c src/gpt.c
TARGET = mcpmux

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)
