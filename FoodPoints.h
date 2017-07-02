#include <SFML/Graphics.hpp>
#include "Point.h"

class SoundSystem;

class FoodPoints
{
	public : 
		FoodPoints(Snake &snake, unsigned int width, unsigned int height);

		void set_style(unsigned int width, std::string food_image);

		void update();

		void draw(sf::RenderWindow &window);

		void set_sound_system(SoundSystem &system);

		void reset();

	private :

		unsigned int m_map_width, m_map_height;
		unsigned int m_point_width;
		sf::Texture m_food_image;

		Snake &m_snake;

		std::vector<Point> m_food_points;

		void add_new_point();

		SoundSystem *m_sound_system;
};
