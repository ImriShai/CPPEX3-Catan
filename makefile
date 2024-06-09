# Compiler
CC = clang++

# Compiler flags
CFLAGS = -std=c++14 -Werror -Wsign-conversion
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

# Source files
GameSrc = $(wildcard *.cpp)
BoardSrc = $(wildcard Board/*.cpp)
cardSrc = $(wildcard Cards/*.cpp)
SRCS = $(GameSrc) $(BoardSrc) $(cardSrc)

# Object files
OBJS = $(SRCS:.cpp=.o)
TARGET = demo

.PHONY: all run demo test tidy valgrind clean
all: demo #test



# Memory check using valgrind
valgrind: demo #test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
#valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }
# Executable name

# Build target
demo: $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
	./demo


# Compile source files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJS) $(TARGET)