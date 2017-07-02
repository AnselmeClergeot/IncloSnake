#include <list>
#include <SFML/Graphics.hpp>

#include "Inputs.h"
#include "FoodPoints.h"
#include "SoundSystem.h"
#include "TileBackground.h"
#include "ScoreSystem.h"
#include "Gui.h"

const unsigned int WINDOW_WIDTH = 500;
const unsigned int WINDOW_HEIGHT = 500;
const unsigned int MAP_WIDTH = 25;
const unsigned int SNAKE_WIDTH = 20;
const unsigned int FOOD_WIDTH = 2 * SNAKE_WIDTH;
const unsigned int START_LENGTH = 1;
const unsigned int SNAKE_SPEED = 25;

const unsigned int START_DELAY = 1, LOOSE_DELAY = 3;

const sf::Color BACKGROUND_COLOR = sf::Color::Blue;
const std::string HEAD_IMAGE_PATH = "images/head_image.png", BODY_IMAGE_PATH = "images/body_image.png", TAIL_IMAGE_PATH = "images/tail_image.png", POINT_IMAGE_PATH = "images/food_image.png";

int main()
{
	sf::RenderWindow game_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Snake");
	game_window.setVerticalSyncEnabled(true);

	Direction head_direction = None; 

	Snake snake(Position {MAP_WIDTH/2, MAP_WIDTH/2}, START_LENGTH, Down, MAP_WIDTH);
	snake.set_style(SNAKE_WIDTH, HEAD_IMAGE_PATH, BODY_IMAGE_PATH, TAIL_IMAGE_PATH);

	FoodPoints food_system(snake, MAP_WIDTH, MAP_WIDTH);
	food_system.set_style(FOOD_WIDTH, POINT_IMAGE_PATH);

	sf::Clock clock;

	SoundSystem sounds("sounds/8_Bit_Portal_-_Still_Alive.wav", "sounds/eat_sound.wav", "sounds/hurt_sound.wav");

	food_system.set_sound_system(sounds);
	
	Direction last_direction = Down;

	TileBackground background("images/background_tile.png", 10, 52);

	ScoreSystem scoring("fonts/PressStart2P.ttf", 30, sf::Color::Black);
	scoring.set_best_score(0);

	Gui gui("fonts/PressStart2P.ttf");
	gui.show_start_menu();

	bool ready_to_start = true;
	bool playing = false;
	bool loose = false;

	while(game_window.isOpen())
	{
		sf::Event event;
		

		sf::Time elapsed = clock.getElapsedTime();

		while(game_window.pollEvent(event))
		{
			read_direction(event, head_direction, last_direction);

			

			switch(event.type)
			{
				case sf::Event::Closed :
					game_window.close();
				break;
			}
		}

		if(ready_to_start && elapsed.asSeconds() > START_DELAY && head_direction != None && head_direction != Up)
		{
			gui.close();
			playing = true;
			ready_to_start = false;
		}

		if(ready_to_start && elapsed.asSeconds() < START_DELAY)
		{
			head_direction = None;
		}

		if(loose)
		{
			gui.show_loose_menu();
			ready_to_start = false;
	
			if(elapsed.asSeconds() > LOOSE_DELAY)
			{
				gui.close();
				gui.show_start_menu();
				
				loose = false;
				ready_to_start = true;
				playing = false;

				snake.reset(Position {MAP_WIDTH/2, MAP_WIDTH/2}, START_LENGTH, Down);		

				food_system.reset();

				clock.restart();
			}
		}
		

		if(playing)
		{
			if(elapsed.asSeconds() > 1/static_cast<float>(SNAKE_SPEED))
			{
				playing = snake.move_head(head_direction);
				loose = !playing;
	
				if(loose)
					sounds.play_hurt_sound();

				clock.restart();
				last_direction = head_direction;

					
			}
		}

		scoring.set_score(snake.get_total_length() - 2); // -2 because we don't count head and tail

		food_system.update();

		game_window.clear();

		background.draw(game_window);
		snake.draw(game_window);		
		food_system.draw(game_window);
		scoring.draw(game_window, WINDOW_WIDTH/2, 20, 0, 0);
		gui.draw(game_window, WINDOW_WIDTH/2, 300);

		game_window.display();
	}

	return EXIT_SUCCESS;
}
