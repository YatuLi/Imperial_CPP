all: HumanTem HumanDyn

HumanDyn: HumanDyn.o
		g++ -Wall -g HumanDyn.o -o HumanDyn
HumanDyn.o: HumanDyn.cpp
		g++ -Wall -g -c HumanDyn.cpp

HumanTem: HumanTem.o
		g++ -Wall -g HumanTem.o -o HumanTem
HumanTem.o: HumanTem.cpp
		g++ -Wall -g -c HumanTem.cpp
clear:
		rm -rf *.o *h.gch HumanTem
