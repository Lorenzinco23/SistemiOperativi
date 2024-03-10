# Compiler
CC = gcc

# Directories
SRCDIR = src
INCDIR = headers
BUILDDIR = build

# Files
SOURCES := $(wildcard $(SRCDIR)/*.c) test.c
OBJECTS := $(patsubst %.c,$(BUILDDIR)/%.o,$(SOURCES))
EXECUTABLE = malloc

# Compiler flags
CFLAGS = -I$(INCDIR) -O3

# Default rule
all: $(BUILDDIR) $(EXECUTABLE)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)/$(SRCDIR)

# Compilation
$(BUILDDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Linking
$(EXECUTABLE): $(OBJECTS)
	$(CC) $^ -o $@

# Cleaning
.PHONY: clean
clean:
	rm -rf $(BUILDDIR) $(EXECUTABLE)