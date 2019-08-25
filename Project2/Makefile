Project2_Loebe_Jamie: main.o Zoo.o Animal.o Tiger.o Penguin.o Turtle.o
	g++ main.o Zoo.o Animal.o Tiger.o Penguin.o Turtle.o -o Project2_Loebe_Jamie

main.o: main.cpp
	g++ -c main.cpp

Zoo.o: Zoo.cpp
	g++ -c Zoo.cpp Zoo.hpp

Animal.o: Animal.cpp
	g++ -c Animal.cpp Animal.hpp

Tiger.o: Tiger.cpp
	g++ -c Tiger.cpp Tiger.hpp

Penguin.o: Penguin.cpp
	g++ -c Penguin.cpp Penguin.hpp

Turtle.o: Turtle.cpp
	g++ -c Turtle.cpp Turtle.hpp

clean:
	rm *.o Project2_Loebe_Jamie
