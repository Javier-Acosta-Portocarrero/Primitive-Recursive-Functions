CXX = g++
CXXFLAGS = -std=c++23 -Wall -Wextra -pedantic
TARGET = build/primitive_recursive_functions

SOURCES = src/fpr.cc \
          src/zero.cc \
          src/successor.cc \
          src/projection.cc \
          src/addition.cc \
          src/multiplication.cc \
          src/power.cc \
          src/main_functions.cc \
          src/main.cc

OBJECTS = $(SOURCES:%.cc=build/%.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

build/%.o: %.cc
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf build/*

cleano:
	rm -rf build/src

.PHONY: all test clean cleano
