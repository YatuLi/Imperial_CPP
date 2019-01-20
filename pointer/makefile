workingPointer: main.o workingPointer.o
		g++ -Wall -g main.o workingPointer.o -o workingPointer
main.o: main.cpp
		g++ -Wall -g -c main.cpp
workingPointer.o: workingPointer.cpp workingPointer.h
		g++ -Wall -g -c workingPointer.cpp workingPointer.h
clear:
		rm -rf *.o *.h.gch workingPointer
