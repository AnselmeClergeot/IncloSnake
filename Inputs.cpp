#include "Inputs.h"
#include "SoundSystem.h"

void read_direction(sf::Event &event, Direction &direction, Direction last_direction, SoundSystem &sounds)
{
	if(event.type == sf::Event::KeyPressed)
	{
		switch(event.key.code)
		{
			case sf::Keyboard::Up :
				if(last_direction != Down)
				{
					direction = Up;		
					sounds.play_move_sound();	
				}
			break;

			case sf::Keyboard::Down :
				if(last_direction != Up)
				{
					direction = Down;
					sounds.play_move_sound();
				}
			break;

			case sf::Keyboard::Left :
				if(last_direction != Right)
				{
					direction = Left;
					sounds.play_move_sound();
				}
			break;

			case sf::Keyboard::Right :
				if(last_direction != Left)
				{
					direction = Right;
					sounds.play_move_sound();
				}
			break;
		}
	}		
}
