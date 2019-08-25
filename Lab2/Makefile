Lab2: main.o inputFile.o outputFile.o
	g++ main.o inputFile.o outputFile.o -o Lab2

main.o: main.cpp
	g++ -c main.cpp

inputFile.o: inputFile.cpp inputFile.hpp
	g++ -c inputFile.cpp

outputFile.o: outputFile.cpp outputFile.hpp
	g++ -c outputFile.cpp

clean:
	rm *.o
