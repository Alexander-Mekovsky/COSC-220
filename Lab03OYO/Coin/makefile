
#Date: September 13 2022
#Class: COSC 220
#Assignment: Lab 03 Part 1 makefile
#Program Objective: To create a makefile that will compile and check all of my other files and combine them into one executable package

PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o Coin.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

Coin.o : Coin.h Coin.cpp
	$(CC) $(CPPFLAGS) -c Coin.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
