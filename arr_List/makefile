all: ExtendableIntArray ExtendableArray ExtendableArrayBetter

ExtendableIntArray: ExtendableIntArray.o
		g++ -Wall -g ExtendableIntArray.o -o ExtendableIntArray
ExtendableIntArray.o: ExtendableIntArray.cpp
		g++ -Wall -g -c ExtendableIntArray.cpp

ExtendableArray: ExtendableArray.o
		g++ -Wall -g ExtendableArray.o -o ExtendableArray
ExtendableArray.o: ExtendableArray.cpp
		g++ -Wall -g -c ExtendableArray.cpp

ExtendableArrayBetter: ExtendableArrayBetter.o
		g++ -Wall -g ExtendableArrayBetter.o -o ExtendableArrayBetter
ExtendableArrayBetter.o: ExtendableArrayBetter.cpp
		g++ -Wall -g -c ExtendableArrayBetter.cpp
clear:
		rm -rf *.o ExtendableArrayBetter ExtendableArray ExtendableInArray
