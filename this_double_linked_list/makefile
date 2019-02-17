DLL: DLLMain.o main.o
		g++ -Wall -g main.o DLLMain.o -o DLL
main.o: main.cpp
		g++ -Wall -g -c main.cpp
DLLMain.o:
		g++ -Wall -g -c DLLMain.cpp DLinkList.h
clear:
		rm -rf *.o *.h.gch DLL
