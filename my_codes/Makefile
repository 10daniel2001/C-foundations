CC = gcc
CFLAGS = -Wall -Wextra -g
BIN_DIR = bin
SRCS = $(wildcard *.c)
BINS = $(patsubst %.c,$(BIN_DIR)/%,$(SRCS))

all: $(BIN_DIR) $(BINS)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)/%: %.c | $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(BIN_DIR)

.PHONY: all clean
