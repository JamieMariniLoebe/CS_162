Final_Project_Loebe_Jamie: main.o Game.o Location.o Player.o Space.o 
	g++ main.o Game.o Location.o Player.o Space.o -o Final_Project_Loebe_Jamie

main.o: main.cpp
	g++ -c main.cpp

Game.o: Game.cpp Game.hpp
	g++ -c Game.cpp

Location.o: Location.cpp Location.hpp
	g++ -c Location.cpp

Space.o: Space.cpp Space.hpp
	g++ -c Space.cpp

clean:
	rm *.o
