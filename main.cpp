#include <list>
#include <SFML/Graphics.hpp>

#include "Snake.h"
#include "Inputs.h"

const unsigned int WINDOW_WIDTH = 600;
const unsigned int WINDOW_HEIGHT = 600;
const unsigned int MAP_WIDTH = 60;
const unsigned int SNAKE_WIDTH = 10;

const unsigned int START_LENGTH = 1;

const sf::Color BACKGROUND_COLOR = sf::Color::Blue;
const std::string HEAD_IMAGE_PATH = "images/head_image.png", BODY_IMAGE_PATH = "images/body_image.png", TAIL_IMAGE_PATH = "images/tail_image.png";

int main()
{
	sf::RenderWindow game_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "IncloSnake");
	game_window.setVerticalSyncEnabled(true);

	Direction head_direction = None; 

	Snake snake(Position {MAP_WIDTH/2, MAP_WIDTH/2}, START_LENGTH, Right);
	snake.set_style(SNAKE_WIDTH, HEAD_IMAGE_PATH, BODY_IMAGE_PATH, TAIL_IMAGE_PATH);
	
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

		if(head_direction != None)
			snake.move_head(head_direction);

		game_window.clear(BACKGROUND_COLOR);

		snake.draw(game_window);		

		game_window.display();
	}

	return EXIT_SUCCESS;
}
