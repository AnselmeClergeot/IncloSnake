#include "Snake.h"

bool Position::operator==(const Position &other)
{
	return x == other.x && y == other.y;
}

Snake::Snake(Position head_position, unsigned int body_length, Direction body_direction) : m_body_length(0), m_scale(1)
{
	m_body_parts.push_back(head_position);
	m_body_parts_directions.push_back(body_direction);
	
	enlarge(body_length);
}

void Snake::set_style(unsigned int body_width, std::string head_image, std::string body_image, std::string tail_image)
{
	m_body_width = body_width;
	
	m_head_image.loadFromFile(head_image);
	m_body_image.loadFromFile(body_image);
	m_tail_image.loadFromFile(tail_image);

	
	m_scale = m_body_width/static_cast<float>(m_head_image.getSize().x);
}

bool Snake::move_head(Direction direction)
{
	Position position_tete = m_body_parts[0];

	m_body_parts.erase(m_body_parts.end() - 1);
	m_body_parts_directions.erase(m_body_parts_directions.end() - 1);

	m_body_parts_directions[m_body_parts_directions.size() - 1] = m_body_parts_directions[m_body_parts_directions.size() - 2];

	Position vector = vector_from_direction(direction);

	m_body_parts.insert(m_body_parts.begin(), Position { position_tete.x + vector.x, position_tete.y + vector.y });
	m_body_parts_directions.insert(m_body_parts_directions.begin(), direction);
}

void Snake::enlarge(unsigned int length)
{
	Position actuelle = m_body_parts[m_body_length];
	Direction direction = m_body_parts_directions[m_body_length];
	Position vector = inversed_vector(direction);

	for(int i = 0; i < length; i++)
	{
		actuelle.x += vector.x;
		actuelle.y += vector.y;

		m_body_parts.push_back(actuelle);
		m_body_parts_directions.push_back(direction);

		++m_body_length;
	}
}

unsigned int Snake::get_body_width() const
{
	return m_body_width;
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

		sprite.setOrigin(32, 32);

		sprite.setPosition(pos.x * m_body_width + 32 * m_scale, pos.y * m_body_width + 32 * m_scale);

		sprite.setScale(m_scale, m_scale);
		

		sprite.setRotation(angle_from_direction(m_body_parts_directions[i]));
		
		window.draw(sprite);
	}
}

Position Snake::get_head_position() const
{
	Position grid_position = m_body_parts[0];

	return Position {grid_position.x * m_body_width, grid_position.y * m_body_width};
}

Position Snake::vector_from_direction(Direction direction) const
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

Position Snake::inversed_vector(Direction direction) const
{
	Position vector = vector_from_direction(direction);

	return Position {-vector.x, -vector.y};
}

unsigned int Snake::angle_from_direction(Direction direction) const
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

bool Snake::cover(Position position, unsigned int area_width) const
{
	for(int y = position.y; y < position.y + area_width; ++y)
	{
		for(int x = position.x; x < position.x + area_width; ++x)
		{
			Position current = {x, y};

			for(Position body : m_body_parts)
			{
				if(current == body)
					return true;
			}
		}
	}

	return false;
}

unsigned int Snake::get_total_length() const
{
	return m_body_parts.size();
}
