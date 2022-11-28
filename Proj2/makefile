prog: proj2Test.o 
	g++ -o prog proj2Test.o 

proj2Test.o: proj2Test.cpp miniDList.h miniDListQueue.h miniDListStack.h miniArrayStack.h miniArrayQueue.h RuntimeException.h
	g++ -g -Wall -std=c++11 -c proj2Test.cpp

clean:
	rm -f prog *.o

rebuild:
	make clean
	make