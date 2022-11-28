PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o List.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

List.o : List.h
	$(CC) $(CPPFLAGS) -c List.h

Feet.o : Feet.h Feet.cpp
	$(CC) $(CPPFLAGS) -c List.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make