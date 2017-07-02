#include "TileBackground.h"

TileBackground::TileBackground(std::string texture, unsigned int map_width, unsigned int tile_width) : m_map_width(map_width), m_tile_width(tile_width)
{
	m_texture.loadFromFile(texture);
}

void TileBackground::draw(sf::RenderWindow &window)
{
	sf::Sprite tile;
	tile.setTexture(m_texture);

	float scale = m_tile_width / static_cast<float>(tile.getGlobalBounds().width);
	
	tile.setScale(scale, scale);
	
	for(int y = 0; y < m_map_width; ++y)
	{
		for(int x = 0; x < m_map_width; ++x)
		{
			tile.setPosition(x * m_tile_width, y * m_tile_width);
			window.draw(tile);
		}
	}
}
