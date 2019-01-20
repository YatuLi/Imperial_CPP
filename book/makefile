Book: Book.o main.o
		g++ -Wall -g Book.o main.o -o Book
Book.o: Book.cpp
		g++ -Wall -g -c Book.cpp Book.h
main.o: main.cpp
		g++ -Wall -g -c main.cpp
clear:
		rm -rf *.o *.h.gch Book
