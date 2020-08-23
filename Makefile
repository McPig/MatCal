# Compiler
CXX      := g++

CXXFLAGS := -Wall -pedantic -std=c++14
DBGFLAGS := -g -DDEBUG

BUILD  := build
TARGET := matcal

SRC := \
	$(wildcard src/main/lib/*.cpp) \
	$(wildcard src/main/*.cpp)

OBJS := $(SRC:%.cpp=$(BUILD)/%.o)

.PHONY: all compile clean


all: compile doc


compile: $(TARGET)


# Create binary target
$(TARGET): $(OBJS)
	$(CXX) $^ -o $@


# Create object files
$(BUILD)/%.o: %.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@


run: compile
	./$(TARGET)


doc:
	doxygen Doxyfile


clean:
	rm -rf $(BUILD)
	rm -f $(TARGET)