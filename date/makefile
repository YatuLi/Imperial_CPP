Date: Date.o main.o
		g++ -Wall -g main.o Date.o -o Date
main.o: main.cpp
		g++ -Wall -g -c main.cpp
Date.o:
		g++ -Wall -g -c Date.cpp Date.h
clear:
		rm -rf *.o *.h.gch Date
