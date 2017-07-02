#include "../include/FoodPoints.h"
#include "../include/Random.h"
#include <cmath>
#include "../include/SoundSystem.h"

FoodPoints::FoodPoints(Snake &snake, unsigned int width) : m_snake(snake), m_food_points(), m_map_width(width)
{
	srand(time(0));	
}

void FoodPoints::set_sound_system(SoundSystem &system)
{
	m_sound_system = &system;
}

void FoodPoints::set_style(unsigned int width, std::string food_image)
{
	m_point_width = width;
	m_food_image.loadFromFile(food_image);
	add_new_point();
}
void FoodPoints::draw(sf::RenderWindow &window)
{
	for(Point point : m_food_points)
		point.draw(window);
}

void FoodPoints::update()
{
	for(int i = 0; i < m_food_points.size(); ++i)
	{
		Point point = m_food_points[i];

		if(m_snake.get_head_position().x + m_snake.get_body_width() > point.get_position().x && m_snake.get_head_position().x < point.get_position().x + 
			m_point_width && m_snake.get_head_position().y + m_snake.get_body_width() > point.get_position().y && m_snake.get_head_position().y < 
			point.get_position().y + m_point_width)
		{
			m_snake.enlarge(point.get_value());
			m_food_points.erase(m_food_points.begin() + i);	
			add_new_point();

			//Play sound
			m_sound_system->play_eat_sound();
		}
	}
}

void FoodPoints::add_new_point()
{
	//Selecting an empty square

	std::vector<Position> valid_positions;

	for(int y = 0; y < m_map_width - 1; ++y)
	{
		for(int x = 0; x < m_map_width - 1; ++x)
		{
			if(!m_snake.cover(Position {x, y}, 2))
				valid_positions.push_back(Position {x, y});
		}
	}

	Position random_pos = valid_positions[random_int_between(0, valid_positions.size() - 1)];
	
	Point new_point(m_point_width, m_food_image, Position {random_pos.x * m_snake.get_body_width(), random_pos.y * m_snake.get_body_width()});

	m_food_points.push_back(new_point);
}

void FoodPoints::reset()
{
	m_food_points.clear();
	add_new_point();	
}
