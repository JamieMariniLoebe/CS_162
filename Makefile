Lab3_Loebe_Jamie: main.o Die.o LoadedDie.o Game.o 
	g++ main.o Die.o LoadedDie.o Game.o -o Lab3_Loebe_Jamie

main.o: main.cpp 
	g++ -c main.cpp

Die.o: Die.cpp Die.hpp
	g++ -c Die.cpp

LoadedDie.o: LoadedDie.cpp LoadedDie.hpp
	g++ -c LoadedDie.cpp

Game.o: Game.cpp Game.hpp
	g++ -c Game.cpp

clean:
	rm *.o Lab3_Loebe_Jamie
