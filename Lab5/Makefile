Lab5_Loebe_Jamie: main.o recursiveFunctions.o
	g++ main.o recursiveFunctions.o -o Lab5_Loebe_Jamie

main.o: main.cpp
	g++ -c main.cpp

recursiveFunctions.o: recursiveFunctions.cpp reverse.hpp sumArray.hpp triNum.hpp
	g++ -c recursiveFunctions.cpp

clean: rm *.o Lab5_Loebe_Jamie
