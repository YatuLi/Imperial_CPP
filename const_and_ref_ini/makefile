Bk_Pub: Book.o main.o Publisher.o
		g++ -Wall -g Book.o main.o Publisher.o -o Bk_Pub
Book.o: Book.cpp
		g++ -Wall -g -c Book.cpp Book.h
Publisher: Publisher.cpp
		g++ -Wall -g -c Publisher.cpp Publisher.h
main.o: main.cpp
		g++ -Wall -g -c main.cpp
clear:
		rm -rf *.o *.h.gch Bk_Pub
