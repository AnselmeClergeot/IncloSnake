#include <SFML/Graphics.hpp>
#include "../include/Snake.h"

class Point
{
	public :
		Point(unsigned int width, sf::Texture image, Position position);
	
		void draw(sf::RenderWindow &window);

		unsigned int get_value() const;

		Position get_position() const;

	private :
		unsigned int m_width;
		sf::Texture m_image;
		Position m_position;
		unsigned int m_value;
};
