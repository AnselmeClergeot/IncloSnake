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

		void enlarge(const unsigned int length);

		void draw(sf::RenderWindow &window);

		Position get_head_position() const;

	private :
		unsigned int m_body_length;
		std::vector<Position> m_body_parts;
		std::vector<Direction> m_body_parts_directions;

		unsigned int m_body_width;
		sf::Texture m_head_image, m_body_image, m_tail_image;
		
		Position vector_from_direction(const Direction direction) const;
		unsigned int angle_from_direction(const Direction direction) const;
};
