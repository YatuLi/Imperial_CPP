Bus: Bus.o main.o Passenger.o
		g++ -Wall -g main.o Bus.o Passenger.o -o Bus
main.o: main.cpp
		g++ -Wall -g -c main.cpp
Bus.o:
		g++ -Wall -g -c Bus.cpp Bus.h
Passenger.o:
		g++ -Wall -g -c Passenger.cpp Passenger.h
clear:
		rm -rf *.o *.h.gch Bus
