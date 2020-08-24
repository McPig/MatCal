# Compiler
CXX := g++

# Flags and libraries
CXXFLAGS := -Wall -pedantic -std=c++14
DBGFLAGS := -g -DDEBUG
LDLIBS   := -lcppunit

# Directories
SRCDIR := src
BLDDIR := build
OBJDIR := $(BLDDIR)/objs
DOCDIR := docs

# File extensions
SRCEXT = cpp
OBJEXT = o

# Binary target name
TARGET := $(BLDDIR)/program

# Sources
SRCS := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))

# Objects
OBJS := $(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(SRCS:.$(SRCEXT)=.$(OBJEXT)))

# make
all: build doc

# make build
build: $(TARGET)

# make debug
debug: CXXFLAGS += $(DBGFLAGS)
debug: build

# Link
$(TARGET): $(OBJS)
	$(CXX) $^ $(LDLIBS) -o $@

# Compile
$(OBJDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# make run
run: build
	./$(TARGET)

# make doc
doc:
	doxygen Doxyfile

# make clean
clean:
	rm -rf $(BLDDIR) $(DOCDIR)


.PHONY: all build debug run doc clean
