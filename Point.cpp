#include "Point.h"

Point::Point(unsigned int width, sf::Texture image, Position position) : m_width(width), m_image(image), m_position(position), m_value(2)
{

}
	
void Point::draw(sf::RenderWindow &window)
{
	sf::Sprite square;
	square.setTexture(m_image);

	float scale = m_width / static_cast<float>(square.getGlobalBounds().width);

	square.setScale(scale, scale);
	
	square.setPosition(m_position.x, m_position.y);

	window.draw(square);
}

unsigned int Point::get_value() const
{
	return m_value;
}

Position Point::get_position() const
{
	return m_position;
}
