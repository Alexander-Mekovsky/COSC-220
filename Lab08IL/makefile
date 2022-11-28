PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = StackQueueTest.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

StackQueueTest.0 : StackQueueTest.cpp
	$(CC) $(CPPFLAGS) -c StackQueueTest.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make