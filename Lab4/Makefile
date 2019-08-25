Lab4_Loebe_Jamie: main.o Building.o Person.o Student.o Instructor.o University.o
	g++ main.o Building.o Person.o Student.o Instructor.o University.o -o Lab4_Loebe_Jamie

main.o: main.cpp
	g++ -c main.cpp

Building.o: Building.cpp Building.hpp
	g++ -c Building.cpp

Person.o: Person.cpp Person.hpp
	g++ -c Person.cpp

Student.o: Student.cpp Student.hpp
	g++ -c Student.cpp

Instructor.o: Instructor.cpp Instructor.hpp
	g++ -c Instructor.cpp

University.o: University.cpp University.hpp
	g++ -c University.cpp

clean: 
	rm*.o Lab4_Loebe_Jamie
