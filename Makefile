CC ?= cc
CFLAGS ?= -Wall -Wextra -std=c11
TARGET := hello
SRC := hello.c

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $<

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
