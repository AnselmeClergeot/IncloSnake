#include <SFML/Graphics.hpp>

#include "../include/Inputs.h"
#include "../include/FoodPoints.h"
#include "../include/SoundSystem.h"
#include "../include/TileBackground.h"
#include "../include/ScoreSystem.h"
#include "../include/Gui.h"

const unsigned int WINDOW_WIDTH = 500;
const unsigned int MAP_WIDTH = 25;
const unsigned int SNAKE_WIDTH = 20;
const unsigned int FOOD_WIDTH = 2 * SNAKE_WIDTH;
const unsigned int START_LENGTH = 1;
const unsigned int SNAKE_SPEED = 20;
const unsigned int START_DELAY = 1, LOOSE_DELAY = 2;
const Position SNAKE_START_POS { MAP_WIDTH/2, MAP_WIDTH/2 + 2 };
const Direction SNAKE_START_DIRECTION = Up;

const unsigned int BG_TILE_WIDTH = 52;
const unsigned int BG_WIDTH = 10;

const unsigned int SCORE_FONT_SIZE  = 30;
const sf::Color SCORE_FONT_COLOR = sf::Color::White;

const Position SCORE_POS {WINDOW_WIDTH/2, 20};
const Position BEST_SCORE_POS {0, 0};
const Position MENU_POS {WINDOW_WIDTH/2, WINDOW_WIDTH/2};

int main()
{
	sf::RenderWindow game_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_WIDTH), "Inclo the Snake");
	game_window.setVerticalSyncEnabled(true);

	Snake snake(SNAKE_START_POS, START_LENGTH, SNAKE_START_DIRECTION, MAP_WIDTH);
	snake.set_style(SNAKE_WIDTH, "images/head_image.png", "images/body_image.png", "images/tail_image.png");

	FoodPoints food_system(snake, MAP_WIDTH);
	food_system.set_style(FOOD_WIDTH, "images/food_image.png");

	SoundSystem sounds("sounds/8_Bit_Portal_-_Still_Alive.wav", "sounds/eat_sound.wav", "sounds/hurt_sound.wav");
	food_system.set_sound_system(sounds);
	
	TileBackground background("images/background_tile.png", BG_WIDTH, BG_TILE_WIDTH);

	ScoreSystem scoring("fonts/PressStart2P.ttf", SCORE_FONT_SIZE, SCORE_FONT_COLOR);

	Gui gui("fonts/PressStart2P.ttf");

	gui.show_start_menu();

	Direction head_direction = None; 
	Direction last_direction = SNAKE_START_DIRECTION;

	bool ready_to_start = true;
	bool playing = false;
	bool loose = false;

	
	sf::Clock clock;

	sf::Event event;

	while(game_window.isOpen())
	{
		sf::Time elapsed = clock.getElapsedTime();

		while(game_window.pollEvent(event))
		{
			read_direction(event, head_direction, last_direction);

			switch(event.type)
			{
				case sf::Event::Closed :
					game_window.close();
					scoring.write_best_score();
				break;
			}
		}

		//MENU/PLAY/LOSE/LOSE_MENU cycle handling
		if(ready_to_start && elapsed.asSeconds() > START_DELAY && head_direction != None)
		{
			gui.close();
			playing = true;
			ready_to_start = false;
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

				head_direction = None;
				last_direction = Up;

				snake.reset(SNAKE_START_POS, START_LENGTH, SNAKE_START_DIRECTION);		

				food_system.reset();

				clock.restart();
			}
		}
		//---	
	
		if(playing)
		{
			if(elapsed.asSeconds() > 1/static_cast<float>(SNAKE_SPEED))
			{
				playing = snake.move_head(head_direction);
				loose = !playing;

				if(loose)
				{
					sounds.play_hurt_sound();
					scoring.write_best_score();
				}

				clock.restart();
				last_direction = head_direction;
			}
		}


		scoring.set_score(snake.get_total_length() - 2);

		food_system.update();

		game_window.clear();

		background.draw(game_window);
		snake.draw(game_window);		
		food_system.draw(game_window);
		scoring.draw(game_window, SCORE_POS.x, SCORE_POS.y, BEST_SCORE_POS.x, BEST_SCORE_POS.y);
		gui.draw(game_window, MENU_POS.x, MENU_POS.y);

		game_window.display();
	}

	return EXIT_SUCCESS;
}
