Compl: main.o Compl.o
		g++ -Wall -g main.o Compl.o -o Compl
main.o: main.cpp
		g++ -Wall -g -c main.cpp
Compl.o: Compl.cpp Compl.h
		g++ -Wall -g -c Compl.cpp Compl.h
clear:
		rm -rf *.o *.h.gch Compl
