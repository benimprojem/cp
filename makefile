# CP Language Compiler Makefile
# Supports Windows compilation with MinGW or MSVC

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2 -DWINDOWS
TARGET = cpc
SOURCES = src/main.c src/lexer.c src/parser.c src/semantic.c src/codegen.c src/error.c src/utils.c
OBJECTS = $(SOURCES:.c=.o)
INCLUDE_DIR = include
LIB_DIR = lib

# Windows specific settings
ifeq ($(OS),Windows_NT)
    TARGET := $(TARGET).exe
    CFLAGS += -DWIN32
    LDFLAGS += -static
endif

# Default target
all: directories $(TARGET)

# Create necessary directories
directories:
	@mkdir -p bin obj $(LIB_DIR)

# Main executable
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o bin/$(TARGET) $(LDFLAGS)
	@echo "CP Compiler built successfully!"

# Object files
%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Standard library
stdlib: directories
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c lib/io.c -o obj/io.o
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c lib/memory.c -o obj/memory.o
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c lib/string.c -o obj/string.o
	ar rcs $(LIB_DIR)/libcp.a obj/io.o obj/memory.o obj/string.o
	@echo "CP Standard Library built successfully!"

# Test the compiler
test: $(TARGET) stdlib
	@echo "Testing CP Compiler..."
	./bin/$(TARGET) examples/hello.cp
	./bin/$(TARGET) examples/arithmetic.cp
	./bin/$(TARGET) examples/functions.cp

# Clean build files
clean:
	rm -rf bin obj $(OBJECTS) $(LIB_DIR)/*.a

# Install (copy to system path)
install: $(TARGET) stdlib
	cp bin/$(TARGET) /usr/local/bin/ 2>/dev/null || echo "Manual installation required"
	cp $(LIB_DIR)/libcp.a /usr/local/lib/ 2>/dev/null || echo "Manual library installation required"
	cp -r $(INCLUDE_DIR)/cp /usr/local/include/ 2>/dev/null || echo "Manual header installation required"

.PHONY: all directories stdlib test clean install
