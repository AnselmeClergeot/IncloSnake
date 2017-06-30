CXXFLAGS = -std=c++14 -O6 -c
SFMLLIB = -lsfml-graphics -lsfml-window -lsfml-system
OBJECTS = main.o Snake.o Inputs.o

all : $(OBJECTS)
	g++ $(OBJECTS) $(SFMLLIB) -o snake

main.o : main.cpp
	g++ $(CXXFLAGS) main.cpp

Snake.o : Snake.cpp
	g++ $(CXXFLAGS) Snake.cpp

Inputs.o : Inputs.cpp
	g++ $(CXXFLAGS) Inputs.cpp

clean :
	rm snake *.o
