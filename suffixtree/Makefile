# the compiler: gcc for C program, define as g++ for C++
CC = g++

BIN = ../bin/

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# the build target executable:
MAINOUTPUT = $(BIN)suffixtree
MAINOBJECTS = *.cpp

all:
	$(CC) -o $(MAINOUTPUT) $(CFLAGS) $(MAINOBJECTS)

run:
	$(BIN)suffixtree "banana"

clean:
	$(RM) $(TARGET)
