#include "Snake.h"

Snake::Snake(const Position head_position, const unsigned int body_length, const Direction body_direction) : m_body_length(body_length)
{
	m_body_parts.push_back(head_position);


	Position vector = vector_from_direction(body_direction);	
	Position actuelle = head_position;

	for(int i = 0; i < body_length; i++)
	{
		actuelle.x += vector.x;
		actuelle.y += vector.y;

		m_body_parts.push_back(actuelle);
	}
}

void Snake::set_style(const unsigned int body_width, std::string head_image, std::string body_image, std::string tail_image)
{
	m_body_width = body_width;
	
}

bool Snake::move_head(const Direction direction)
{
	Position position_tete = m_body_parts[0];

	m_body_parts.erase(m_body_parts.end() - 1);

	Position vector = vector_from_direction(direction);

	m_body_parts.insert(m_body_parts.begin(), Position { position_tete.x + vector.x, position_tete.y + vector.y });
}

void Snake::draw(sf::RenderWindow &window)
{
	sf::RectangleShape shape(sf::Vector2f(m_body_width, m_body_width));

	for(Position p : m_body_parts)
	{
		shape.setPosition(p.x * m_body_width, p.y * m_body_width);
		window.draw(shape);	
	}

}

std::vector<Position> Snake::get_body() const
{
	return m_body_parts;
}

Position Snake::vector_from_direction(const Direction direction) const
{
	Position vector {0, 0};

	if(direction == Left)
	{
		vector.x = -1;
	}
	else if(direction == Right)
	{
		vector.x = 1;
	}
	else if(direction == Up)
	{
		vector.y = -1;
	}
	else
		vector.y = 1;

	return vector;
}
