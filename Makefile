CC ?= cc
CFLAGS ?= -std=c99 -Wall -Wextra -Wpedantic -Iinclude
LDFLAGS ?=
LDLIBS ?= -lraylib -lm

TARGET := bin/crossy-road
SOURCES := $(wildcard src/*.c)
OBJECTS := $(SOURCES:src/%.c=build/%.o)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

build/%.o: src/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf build bin
