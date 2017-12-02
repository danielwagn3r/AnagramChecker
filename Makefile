# the compiler: gcc for C program, define as g++ for C++
CC = gcc

UNAME = $(shell uname -o)
ifeq ($(UNAME), Msys)
  EXEEXT = .exe
endif

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall -Wextra -Wpedantic -std=c11

# the build target executable:
TARGET = anagram

all: $(TARGET)

$(TARGET)$(EXEEXT): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	$(RM) $(TARGET)$(EXEEXT) $(TARGET).o