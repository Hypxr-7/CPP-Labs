# Compiler
CC := g++

# Compiler flags
CFLAGS := -Wall -Wextra -std=c++20

# Libraries
LIBS := -lraylib

# Source files
SRCS := src/main.cpp src/game.cpp src/ball.cpp src/paddle.cpp src/bricks.cpp

# Object files
OBJS := $(SRCS:.c=.o)

# Executable name
TARGET := breakout.exe

# Build target
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LIBS)
	.\breakout.exe

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(OBJS) $(TARGET)