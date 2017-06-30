#include "Snake.h"

Snake::Snake(const Position head_position, const unsigned int body_length, const Direction body_direction) : m_body_length(body_length)
{
	m_body_parts.push_back(head_position);
	m_body_parts_directions.push_back(body_direction);

	Position vector = vector_from_direction(body_direction);	

	vector.x = - vector.x;
	vector.y = - vector.y;	

	Position actuelle = head_position;

	for(int i = 0; i < body_length; i++)
	{
		actuelle.x += vector.x;
		actuelle.y += vector.y;

		m_body_parts.push_back(actuelle);
		m_body_parts_directions.push_back(body_direction);
	}
}

void Snake::set_style(const unsigned int body_width, std::string head_image, std::string body_image, std::string tail_image)
{
	m_body_width = body_width;
	
	m_head_image.loadFromFile(head_image);
	m_body_image.loadFromFile(body_image);
	m_tail_image.loadFromFile(tail_image);
}

bool Snake::move_head(const Direction direction)
{
	Position position_tete = m_body_parts[0];

	m_body_parts.erase(m_body_parts.end() - 1);
	m_body_parts_directions.erase(m_body_parts_directions.end() - 1);

	Position vector = vector_from_direction(direction);

	m_body_parts.insert(m_body_parts.begin(), Position { position_tete.x + vector.x, position_tete.y + vector.y });
	m_body_parts_directions.insert(m_body_parts_directions.begin(), direction);
}

void Snake::draw(sf::RenderWindow &window)
{
	sf::Sprite sprite;

	for(int i = 0; i < m_body_parts.size(); ++i)
	{
		if(i == 0)
			sprite.setTexture(m_head_image);
		else if(i == m_body_parts.size() - 1)
			sprite.setTexture(m_tail_image);
		else
			sprite.setTexture(m_body_image);
		
		Position pos = m_body_parts[i];

		sprite.setPosition(pos.x * m_body_width, pos.y * m_body_width);

		sprite.setOrigin(32, 32);
		
		float scale = m_body_width/static_cast<float>(m_head_image.getSize().x);

		sprite.setScale(scale, scale);
		sprite.setRotation(angle_from_direction(m_body_parts_directions[i]));
		
		window.draw(sprite);
	}
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
	else if(direction == Down)
		vector.y = 1;

	return vector;
}

unsigned int Snake::angle_from_direction(const Direction direction) const
{
	if(direction == Left)
		return 90;
	if(direction == Right)
		return 270;
	if(direction == Up)
		return 180;
	if(direction == Down || direction == None)
		return 0;
}
