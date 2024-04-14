# Makefile

# Define compiler
CC=gcc

# Define compiler flags
CFLAGS=-Wall -Werror

# Define the target executable
TARGET=CheatSheetCode

# Define phony targets
.PHONY: all clean

# Default target
all: $(TARGET)

# Rule for building the target executable
$(TARGET): CheatSheetCode.c
	$(CC) $(CFLAGS) CheatSheetCode.c -o $(TARGET)

# Rule for cleaning up generated files
clean:
	rm -f $(TARGET)
