#include "Inputs.h"
#include "SoundSystem.h"

void read_direction(sf::Event &event, Direction &direction, Direction last_direction)
{
	if(event.type == sf::Event::KeyPressed)
	{
		switch(event.key.code)
		{
			case sf::Keyboard::Up :
				if(last_direction != Down && last_direction != Up)
					direction = Up;		
			break;

			case sf::Keyboard::Down :
				if(last_direction != Up && last_direction != Down)
					direction = Down;
			break;

			case sf::Keyboard::Left :
				if(last_direction != Right && last_direction != Left)
					direction = Left;
			break;

			case sf::Keyboard::Right :
				if(last_direction != Left && last_direction != Right)
					direction = Right;
			break;
		}
	}
}
