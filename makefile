Test: test.o
	g++ -g -std=c++11 -Wall test.o -o Test

test.o: test.cpp LinkedList.h LinkedList.hpp Node.h Node.hpp
	g++ -g -std=c++11 -Wall -c test.cpp

clean:
	rm *.o Test
