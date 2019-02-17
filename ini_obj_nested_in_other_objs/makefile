Pt_Te: Point.o main.o Territory.o
		g++ -Wall -g Point.o main.o Territory.o -o Pt_Te
Point.o: Point.cpp
		g++ -Wall -g -c Point.cpp Point.h
Territory: Territory.cpp
		g++ -Wall -g -c Territory.cpp Territory.h
main.o: main.cpp
		g++ -Wall -g -c main.cpp
clear:
		rm -rf *.o *.h.gch Pt_Te
