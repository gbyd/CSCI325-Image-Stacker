# file Makefile
# author Gabbie Dement
# date 2026-03-05
# brief Builds the image stacking program

CC = g++

TARGET = stacker

CFLAGS = -c -Wall -Wextra

all: $(TARGET)

$(TARGET): main.o Stacker.o
	$(CC) -g main.o Stacker.o -o $(TARGET)

main.o: main.cpp Stacker.h
	$(CC) $(CFLAGS) main.cpp

Stacker.o: Stacker.cpp Stacker.h
	$(CC) $(CFLAGS) Stacker.cpp

clean:
	$(RM) $(TARGET) *.o *~
