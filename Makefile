Lab1_Loebe_Jamie: matrixCalculator.o readMatrix.o determinant.o
	g++ matrixCalculator.o readMatrix.o determinant.o -o Lab1_Loebe_Jamie

matrixCalculator.o: matrixCalculator.cpp
	g++ -c matrixCalculator.cpp

readMatrix.o: readMatrix.cpp readMatrix.hpp
	g++ -c readMatrix.cpp

determinant.o: determinant.cpp determinant.hpp
	g++ -c determinant.cpp

clean: 
	rm *.o Lab1_Loebe_Jamie
