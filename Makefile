# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Iinclude

# Directories
SRCDIR = src
INCDIR = include
TESTDIR = tests
BUILDDIR = build

# Source files
SRC_FILES = $(SRCDIR)/mystring.c $(SRCDIR)/myconversion.c

# Object files
SRC_OBJS = $(SRC_FILES:.c=.o)

# Test source files
TEST_FILES_MYSTRING = $(TESTDIR)/test_mystring.c
TEST_FILES_MYCONVERSION = $(TESTDIR)/test_myconversion.c

# Test object files
TEST_OBJS_MYSTRING = $(TEST_FILES_MYSTRING:.c=.o)
TEST_OBJS_MYCONVERSION = $(TEST_FILES_MYCONVERSION:.c=.o)

# Executables
TEST_EXEC_MYSTRING = $(BUILDDIR)/test_mystring
TEST_EXEC_MYCONVERSION = $(BUILDDIR)/test_myconversion

# Default rule to build and run all tests
all: test_mystring test_myconversion

# Rule to build and run tests for mystring
test_mystring: $(TEST_EXEC_MYSTRING)
	@echo "Running mystring tests..."
	./$(TEST_EXEC_MYSTRING)

# Rule to build and run tests for myconversion
test_myconversion: $(TEST_EXEC_MYCONVERSION)
	@echo "Running myconversion tests..."
	./$(TEST_EXEC_MYCONVERSION)

# Rule to build the mystring test executable
$(TEST_EXEC_MYSTRING): $(SRC_OBJS) $(TEST_OBJS_MYSTRING) | $(BUILDDIR)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to build the myconversion test executable
$(TEST_EXEC_MYCONVERSION): $(SRC_OBJS) $(TEST_OBJS_MYCONVERSION) | $(BUILDDIR)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile source files into object files
$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile test files into object files
$(TESTDIR)/%.o: $(TESTDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Create build directory if it doesn't exist
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Rule to clean build artifacts
clean:
	rm -rf $(BUILDDIR) $(SRC_OBJS) $(TEST_OBJS_MYSTRING) $(TEST_OBJS_MYCONVERSION)

# Phony targets
.PHONY: all clean test_mystring test_myconversion
