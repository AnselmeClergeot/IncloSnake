#include <vector>
#include <SFML/Graphics.hpp>
#include "Direction.h"

struct Position
{
	int x, y;
};

class Snake
{
	public :
		Snake(const Position head_position, const unsigned int body_length, const Direction body_direction);
		
		void set_style(const unsigned int width, std::string head_image, std::string body_image, std::string tail_image);
		
		bool move_head(const Direction direction);

		std::vector<Position> get_body() const;

		void draw(sf::RenderWindow &window);

	private :
		unsigned int m_body_length;
		std::vector<Position> m_body_parts;

		unsigned int m_body_width;
		sf::Texture m_head_image, m_body_image, m_tail_image;
		
		Position vector_from_direction(const Direction direction) const;
};