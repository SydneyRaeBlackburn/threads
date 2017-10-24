#Troy Ricks: cssc1101
#Sydney Blackburn: cssc1112

#Class: CS570, Professor Leonard, Summer 2017
#Due: June 5, 2017
#Project: Assignment #1, Process Manager
#File: Makefile

CC = gcc -pthread 
CFLAGS = -c 
TARGET = bots

all: $(TARGET)

$(TARGET): bots.o
	$(CC) bots.o -o $(TARGET)

bots.o: bots.c
	$(CC) $(CFLAGS) bots.c

clean:
	rm -f core *.o $(TARGET)


