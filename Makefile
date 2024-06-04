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
# add "$(SRCDIR)/<file>.c" to below line for any <file>.c in $(SRCDIR). 
SRC_FILES = $(SRCDIR)/mystring.c $(SRCDIR)/myconversion.c $(SRCDIR)/mymenu.c

# Object files
SRC_OBJS = $(SRC_FILES:.c=.o)

# Test source files
# add "TEST_FILES_SAMPLE = $(TESTDIR)/test_mysample.c" for any test_mysample.c in $(TESTDIR)
TEST_FILES_MYSTRING = $(TESTDIR)/test_mystring.c
TEST_FILES_MYCONVERSION = $(TESTDIR)/test_myconversion.c
TEST_FILES_MYMENU = $(TESTDIR)/test_mymenu.c

# Test object files
# add "TEST_OBJS_MYSAMPLE = $(TEST_FILES_MYSAMPLE:.c=.o)" to create object file for test_mysample.c
TEST_OBJS_MYSTRING = $(TEST_FILES_MYSTRING:.c=.o)
TEST_OBJS_MYCONVERSION = $(TEST_FILES_MYCONVERSION:.c=.o)
TEST_OBJS_MYMENU = $(TEST_FILES_MYMENU:.c=.o)

# Executables
# add "TEST_EXEC_MYSAMPLE = $(BUILDDIR)/test_mysaple" variable to crreate for test_mysaple.
TEST_EXEC_MYSTRING = $(BUILDDIR)/test_mystring
TEST_EXEC_MYCONVERSION = $(BUILDDIR)/test_myconversion
TEST_EXEC_MYMENU = $(BUILDDIR)/test_mymenu

# Default rule to build and run all tests
# add test_mysaple
all: test_mystring test_myconversion test_mymenu

# Rules to build and run tests
# add the below code snippet,
# # Rule to build and run tests for mysample
# test_mysample: $(TEST_EXEC_MYSAPLE)
# 	@echo "Running mysample tests..."
# 	./$(TEST_EXEC_MYSAMPLE)
# to add test for mysample.

# Rule to build and run tests for mystring
test_mystring: $(TEST_EXEC_MYSTRING)
	@echo "Running mystring tests..."
	./$(TEST_EXEC_MYSTRING)

# Rule to build and run tests for myconversion
test_myconversion: $(TEST_EXEC_MYCONVERSION)
	@echo "Running myconversion tests..."
	./$(TEST_EXEC_MYCONVERSION)

# Rule to build and run tests for mymenu
test_mymenu: $(TEST_EXEC_MYMENU)
	@echo "Running mymenu tests..."
	./$(TEST_EXEC_MYMENU)

# Rules to build the ececutable
# add the below code snippet,
# # Rule to build the mysample test executable
# $(TEST_EXEC_MYSAMPLE): $(SRC_OBJS) $(TEST_OBJS_MYSAMPLE) | $(BUILDDIR)
# 	$(CC) $(CFLAGS) -o $@ $^
# to build the mysample test executable

# Rule to build the mystring test executable
$(TEST_EXEC_MYSTRING): $(SRC_OBJS) $(TEST_OBJS_MYSTRING) | $(BUILDDIR)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to build the myconversion test executable
$(TEST_EXEC_MYCONVERSION): $(SRC_OBJS) $(TEST_OBJS_MYCONVERSION) | $(BUILDDIR)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to build the mymenu test executable
$(TEST_EXEC_MYMENU): $(SRC_OBJS) $(TEST_OBJS_MYMENU) | $(BUILDDIR)
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
# add $(TEST_OBJS_MYSAMPLE) to clean
clean:
	rm -rf $(BUILDDIR) $(SRC_OBJS) $(TEST_OBJS_MYSTRING) $(TEST_OBJS_MYCONVERSION) $(TEST_OBJS_MYMENU)

# Phony targets
# add "sampletarget"
.PHONY: all clean test_mystring test_myconversion test_mymenu
