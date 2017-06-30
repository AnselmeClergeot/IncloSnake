#include "Inputs.h"

void read_direction(sf::Event &event, Direction &direction)
{
	if(event.type == sf::Event::KeyPressed)
	{
		switch(event.key.code)
		{
			case sf::Keyboard::Up :
				if(direction != Down)
					direction = Up;		
			break;

			case sf::Keyboard::Down :
				if(direction != Up)
					direction = Down;
			break;

			case sf::Keyboard::Left :
				if(direction != Right)
					direction = Left;
			break;

			case sf::Keyboard::Right :
				if(direction != Left)
					direction = Right;
			break;
		}
	}		
}
