# Compiler
CC = clang++

# Compiler flags
CFLAGS = -std=c++14 -g -Wall

# Source files
SRCS = $(wildcard *.cpp)


# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = demo

# Build target
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile source files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJS) $(TARGET)