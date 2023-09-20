# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Source directory, where your .c files are located
SRC_DIR = src

# List of source files (automatically finds all .c files in SRC_DIR)
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)

# Generate object file names from source file names
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, %.o, $(SRC_FILES))

# Name of the final executable
EXECUTABLE = my_program

# Default target, build the executable
all: $(EXECUTABLE)

# Rule to build the executable
$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile individual source files into object files
%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean up object files
clean:
	rm -f $(OBJ_FILES)

# Clean up object files and the executable
clean-all: clean
	rm -f $(EXECUTABLE)
