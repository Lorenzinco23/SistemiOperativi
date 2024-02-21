# Compiler
CC = gcc

# Directories
SRCDIR = src
INCDIR = headers
BUILDDIR = build

# Files
SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(SOURCES:$(SRCDIR)/%.c=$(BUILDDIR)/%.o)
EXECUTABLE = malloc

# Compiler flags
CFLAGS = -I$(INCDIR) -O3

# Default rule
all: $(EXECUTABLE)

# Linking
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

# Compilation
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) -c $< -o $@ $(CFLAGS)

# Clean rule
clean:
	rm -rf $(BUILDDIR) $(EXECUTABLE)

# Phony targets
.PHONY: all clean
