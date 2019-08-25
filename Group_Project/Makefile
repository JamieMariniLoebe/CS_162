#####################################################################
# Program Name: Group Project
# Author: Kimberly Cu, Brandon Goza, Matthew Harbinson, Jamie Loebe,
# Jordan Sperry
# Date: 10/23/18
# Description: This is a Makefile which organizes code compilation.
# This particular Makefile compiles the main.cpp, menu.cpp ant.cpp, board.cpp,
# critter.cpp, and doodlebug.cpp into a main executable. This Makefile
# also allows for the user to delete all *.o files by typing "make clean."
#####################################################################

# Create executable by compiling
main: main.o board.o critter.o ant.o doodlebug.o menu.o
	g++ main.o board.o critter.o ant.o doodlebug.o menu.o -o main

# Create main object file by compling main.cpp
main.o: main.cpp
	g++ -c main.cpp

# Create menu object file by compling menu.cpp and menu.hpp
menu.o: menu.cpp menu.hpp
	g++ -c menu.cpp

# Create board object file by compling board.cpp and board.hpp
board.o: board.cpp board.hpp
	g++ -c board.cpp

# Create tile critter file by compling critter.cpp and critter.hpp
critter.o: critter.cpp critter.hpp
	g++ -c critter.cpp

# Create ant object file by compling ant.cpp and ant.hpp
ant.o: ant.cpp ant.hpp
	g++ -c ant.cpp

# Create doodlebug object file by compling doodlebug.cpp and doodlebug.hpp
doodlebug.o: doodlebug.cpp doodlebug.hpp
	g++ -c doodlebug.cpp

# Clean all object files and executable, main
clean:
	rm *.o main
