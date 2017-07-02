#include <SFML/Graphics.hpp>

class TileBackground
{
	public :
		TileBackground(std::string texture, unsigned int map_width, unsigned int tile_width);

		void draw(sf::RenderWindow &window);

	private :
		sf::Texture m_texture;
		unsigned int m_map_width, m_tile_width;
};
