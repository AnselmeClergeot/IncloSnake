CXXFLAGS = -std=c++14 -O6 -c
SFMLLIB = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
OBJECTS = main.o Snake.o Inputs.o FoodPoints.o Point.o Random.o SoundSystem.o TileBackground.o ScoreSystem.o Gui.o
CCXX = g++ 

all : $(OBJECTS)
	$(CCXX) $(OBJECTS) $(SFMLLIB) -o snake

main.o : main.cpp
	$(CCXX) $(CXXFLAGS) main.cpp

Snake.o : Snake.cpp
	$(CCXX) $(CXXFLAGS) Snake.cpp

Inputs.o : Inputs.cpp
	$(CCXX)$(CXXFLAGS) Inputs.cpp

FoodPoints.o : FoodPoints.cpp
	$(CCXX) $(CXXFLAGS) FoodPoints.cpp

Point.o : Point.cpp
	$(CCXX) $(CXXFLAGS) Point.cpp

Random.o : Random.cpp
	$(CCXX) $(CXXFLAGS) Random.cpp

SoundSystem.o : SoundSystem.cpp
	$(CCXX) $(CXXFLAGS) SoundSystem.cpp

TileBackground.o : TileBackground.cpp
	$(CCXX) $(CXXFLAGS) TileBackground.cpp

ScoreSystem.o : ScoreSystem.cpp
	$(CCXX) $(CXXFLAGS) ScoreSystem.cpp

Gui.o : Gui.cpp
	$(CCXX) $(CXXFLAGS) Gui.cpp

clean :
	rm snake *.o
