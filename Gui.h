#include <SFML/Graphics.hpp>

class Gui
{
	public :
		Gui(std::string font_path);

		void show_loose_menu();
		void show_start_menu();		

		void draw(sf::RenderWindow &window, unsigned int x, unsigned int y);

		bool can_play() const;

		void close();

	private :
		bool m_activated;
		sf::Font m_font;
		sf::Text m_text;
};
