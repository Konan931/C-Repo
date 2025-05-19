# compile with: make all
# clean with: make clean
# This makefile is for a C project that includes multiple source files
# and uses the GCC compiler.
# It compiles the source files into object files and links them into an executable.
CC = gcc
# The compiler flags
CFLAGS = -Wall -Wextra -pedantic -g -std=c11
# The source files
# The source files are in the src directory
# The object files will be generated from the source files
# The object files are in the obj directory
SRC = src/main.c src/string_utils.c src/hash_utils.c src/memory_utils.c src/number_utils.c \
      src/debug_utils.c src/file_utils.c src/thread_utils.c src/data_structures.c
# Add more source files as needed
# The object files will be generated from the source files
OBJ = $(SRC:.c=.o)
# Executable name
EXEC = ultimate_tool

# Target: Default build
# This is the default target
# It is the first target in the makefile
# It is the target that will be built when you run make
# It is the target that will be built when you run make all
# It is the target that will be built when you run make clean
# It is the target that will be built when you run make run
# It is the target that will be built when you run make debug
# It is the target that will be built when you run make release
# It is the target that will be built when you run make test
# It is the target that will be built when you run make install
# It is the target that will be built when you run make uninstall
all: $(EXEC)
# The $(EXEC) target depends on the object files
# The $(OBJ) target depends on the source files
# The $(OBJ) target is generated from the $(SRC) target
# The $(EXEC) target is generated from the $(OBJ) target
# The $(EXEC) target is the final executable
# The $(OBJ) target is the object files
# The $(SRC) target is the source files
# The $(EXEC) target is the final executable

# Linking
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# Compiling
# This rule compiles the source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
# The $< is the first prerequisite
# The $@ is the target name
# The -c flag tells the compiler to compile the source file into an object file
# The -o flag tells the compiler to output the object file with the specified name
# The -g flag tells the compiler to include debugging information
# The -Wall flag tells the compiler to enable all warnings
# The -Wextra flag tells the compiler to enable extra warnings
# The -pedantic flag tells the compiler to issue all warnings
# The -std=c11 flag tells the compiler to use the C11 standard
# The -I flag tells the compiler to include the specified directory
# The -L flag tells the compiler to link the specified library
# The -l flag tells the compiler to link the specified library
# The -o flag tells the compiler to output the executable with the specified name
# The -lm flag tells the compiler to link the math library
# The -lpthread flag tells the compiler to link the pthread library
# The -lssl flag tells the compiler to link the OpenSSL library
# The -lcrypto flag tells the compiler to link the OpenSSL crypto library
# The -lreadline flag tells the compiler to link the readline library
# The -lboost_system flag tells the compiler to link the Boost system library
# The -lboost_filesystem flag tells the compiler to link the Boost filesystem library
# The -lboost_thread flag tells the compiler to link the Boost thread library
# The -lboost_regex flag tells the compiler to link the Boost regex library
# The -lboost_program_options flag tells the compiler to link the Boost program options library
# The -lboost_date_time flag tells the compiler to link the Boost date time library
# The -lboost_chrono flag tells the compiler to link the Boost chrono library
# The -lboost_atomic flag tells the compiler to link the Boost atomic library
# The -lboost_context flag tells the compiler to link the Boost context library
# The -lboost_coroutine flag tells the compiler to link the Boost coroutine library
# The -lboost_graph flag tells the compiler to link the Boost graph library
# The -lboost_iostreams flag tells the compiler to link the Boost iostreams library
# The -lboost_locale flag tells the compiler to link the Boost locale library
# The -lboost_log flag tells the compiler to link the Boost log library
# The -lboost_log_setup flag tells the compiler to link the Boost log setup library
# The -lboost_math_c99 flag tells the compiler to link the Boost math C99 library
# The -lboost_math_c99f flag tells the compiler to link the Boost math C99f library
# The -lboost_math_c99l flag tells the compiler to link the Boost math C99l library

# clean: Remove the object files and the executable
# This is useful to start fresh
# and ensure that all files are recompiled
# when you run make again
# This is useful for debugging
clean:
	rm -f $(OBJ) $(EXEC)

# Run the program with the default target
run: $(EXEC)
	./$(EXEC)

# The .PHONY target is used to indicate that the target does not represent a file
.PHONY: all clean run
# This is a phony target
# It is not a file, but a command
# It is used to indicate that the target does not represent a file