CXXFLAGS = -std=c++14 -O6 -c
SFMLLIB = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
OBJECTS = main.o Snake.o Inputs.o FoodPoints.o Point.o Random.o SoundSystem.o TileBackground.o ScoreSystem.o Gui.o

all : $(OBJECTS)
	g++ $(OBJECTS) $(SFMLLIB) -o snake

main.o : main.cpp
	g++ $(CXXFLAGS) main.cpp

Snake.o : Snake.cpp
	g++ $(CXXFLAGS) Snake.cpp

Inputs.o : Inputs.cpp
	g++ $(CXXFLAGS) Inputs.cpp

FoodPoints.o : FoodPoints.cpp
	g++ $(CXXFLAGS) FoodPoints.cpp

Point.o : Point.cpp
	g++ $(CXXFLAGS) Point.cpp

Random.o : Random.cpp
	g++ $(CXXFLAGS) Random.cpp

SoundSystem.o : SoundSystem.cpp
	g++ $(CXXFLAGS) SoundSystem.cpp

TileBackground.o : TileBackground.cpp
	g++ $(CXXFLAGS) TileBackground.cpp

ScoreSystem.o : ScoreSystem.cpp
	g++ $(CXXFLAGS) ScoreSystem.cpp

Gui.o : Gui.cpp
	g++ $(CXXFLAGS) Gui.cpp

clean :
	rm snake *.o
