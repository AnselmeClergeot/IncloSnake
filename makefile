CXXFLAGS = -std=c++14 -O6 -c
SFMLLIB = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
OBJECTS = main.o Snake.o Inputs.o FoodPoints.o Point.o Random.o SoundSystem.o TileBackground.o ScoreSystem.o Gui.o
CCXX = g++  

all : $(OBJECTS)
	$(CCXX) $(OBJECTS) $(SFMLLIB) -o snake

main.o : src/main.cpp
	$(CCXX) $(CXXFLAGS) src/main.cpp

Snake.o : src/Snake.cpp
	$(CCXX) $(CXXFLAGS) src/Snake.cpp

Inputs.o : src/Inputs.cpp
	$(CCXX)$(CXXFLAGS) src/Inputs.cpp

FoodPoints.o : src/FoodPoints.cpp
	$(CCXX) $(CXXFLAGS) src/FoodPoints.cpp

Point.o : src/Point.cpp
	$(CCXX) $(CXXFLAGS) src/Point.cpp

Random.o : src/Random.cpp
	$(CCXX) $(CXXFLAGS) src/Random.cpp

SoundSystem.o : src/SoundSystem.cpp
	$(CCXX) $(CXXFLAGS) src/SoundSystem.cpp

TileBackground.o : src/TileBackground.cpp
	$(CCXX) $(CXXFLAGS) src/TileBackground.cpp

ScoreSystem.o : src/ScoreSystem.cpp
	$(CCXX) $(CXXFLAGS) src/ScoreSystem.cpp

Gui.o : src/Gui.cpp
	$(CCXX) $(CXXFLAGS) src/Gui.cpp

clean :
	rm snake *.o
