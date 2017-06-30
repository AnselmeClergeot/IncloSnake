#include <list>
#include <SFML/Graphics.hpp>

#include "Snake.h"
#include "Inputs.h"

const unsigned int WINDOW_WIDTH = 600;
const unsigned int WINDOW_HEIGHT = 600;
const unsigned int MAP_WIDTH = 600;
const unsigned int SNAKE_WIDTH = 1;

const unsigned int START_LENGTH = 1000;

const sf::Color BACKGROUND_COLOR = sf::Color::Black;
const sf::Color SNAKE_COLOR = sf::Color::Green;

int main()
{
	sf::RenderWindow game_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "IncloSnake");
	game_window.setVerticalSyncEnabled(true);

	Direction head_direction = None; 
	Snake snake(Position {MAP_WIDTH/2, MAP_WIDTH/2}, START_LENGTH, Right, SNAKE_WIDTH);
	
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

		snake.move_head(head_direction);

		game_window.clear(BACKGROUND_COLOR);

		snake.draw(game_window);		

		game_window.display();
	}

	return EXIT_SUCCESS;
}
