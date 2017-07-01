#include <list>
#include <SFML/Graphics.hpp>

#include "Inputs.h"
#include "FoodPoints.h"
#include "SoundSystem.h"

const unsigned int WINDOW_WIDTH = 600;
const unsigned int WINDOW_HEIGHT = 600;
const unsigned int MAP_WIDTH = 60;
const unsigned int SNAKE_WIDTH = 10;
const unsigned int FOOD_WIDTH = 2 * SNAKE_WIDTH;
const unsigned int START_LENGTH = 5;
const unsigned int SNAKE_SPEED = 30;

const sf::Color BACKGROUND_COLOR = sf::Color::Blue;
const sf::Color FOOD_COLOR = sf::Color::Green;
const std::string HEAD_IMAGE_PATH = "images/head_image.png", BODY_IMAGE_PATH = "images/body_image.png", TAIL_IMAGE_PATH = "images/tail_image.png", POINT_IMAGE_PATH = "images/point.png";

int main()
{
	sf::RenderWindow game_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Snake");
	game_window.setVerticalSyncEnabled(true);

	Direction head_direction = None; 

	Snake snake(Position {MAP_WIDTH/2, MAP_WIDTH/2}, START_LENGTH, Down);
	snake.set_style(SNAKE_WIDTH, HEAD_IMAGE_PATH, BODY_IMAGE_PATH, TAIL_IMAGE_PATH);

	FoodPoints food_system(snake, MAP_WIDTH, MAP_WIDTH);
	food_system.set_style(FOOD_WIDTH, FOOD_COLOR);

	sf::Clock clock;

	SoundSystem sounds("sounds/8_Bit_Portal_-_Still_Alive.wav", "sounds/eat_sound.wav");
	
	while(game_window.isOpen())
	{
		sf::Event event;

		while(game_window.pollEvent(event))
		{

			read_direction(event, head_direction);
			
			switch(event.type)
			{
				case sf::Event::Closed :
					game_window.close();
				break;
			}
		}

		
		sf::Time elapsed = clock.getElapsedTime();

		if(head_direction != None && elapsed.asSeconds() > 1/static_cast<float>(SNAKE_SPEED))
		{
			snake.move_head(head_direction);
			clock.restart();
		}

		food_system.update();

		game_window.clear(BACKGROUND_COLOR);

		snake.draw(game_window);		
		food_system.draw(game_window);

		game_window.display();
	}

	return EXIT_SUCCESS;
}
