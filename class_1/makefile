BMI: main.o BMI.o
		g++ -Wall -g main.o BMI.o -o BMI
main.o: main.cpp
		g++ -Wall -g -c main.cpp
BMI.o: BMI.cpp
		g++ -Wall -g -c BMI.cpp BMI.h
clear:
		rm -rf *.o *.h.gch BMI
