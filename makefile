# Compiler
CC = clang++

# Compiler flags
CFLAGS = -std=c++14 -Werror -Wsign-conversion
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

# Source files
GameSrc = Catan.cpp Player.cpp Consts.cpp
BoardSrc = $(wildcard Board/*.cpp)
cardSrc = $(wildcard Cards/*.cpp)
DEMOSRCS = $(GameSrc) $(BoardSrc) $(cardSrc) Demo.cpp
TESTSRCS = $(GameSrc) $(BoardSrc) $(cardSrc) $(wildcard Test/*.cpp)

# Object files
DEMOOBJS = $(DEMOSRCS:.cpp=.o)
TESTOBJS = $(TESTSRCS:.cpp=.o)
TARGET = demo

.PHONY: all run demo test tidy valgrind clean
all: demo #test



# Memory check using valgrind
valgrind: demo test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo <demoInput.txt 2>&1 | { egrep -i "HEAP|at exit" || true; } 	

# Executable name

# Build target
demo: $(DEMOOBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(DEMOOBJS)
# ./demo

test: $(TESTOBJS)
	$(CC) $(CFLAGS) -o test $(TESTOBJS)
	


# Compile source files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f *.o demo test Board/*.o Cards/*.o Test/*.o