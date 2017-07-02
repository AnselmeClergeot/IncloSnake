#include "../include/Gui.h"

Gui::Gui(std::string font_path)
{
	m_font.loadFromFile(font_path);
	m_text.setFont(m_font);
}

void Gui::show_loose_menu()
{
	m_text.setCharacterSize(25);
	m_activated = true;
	m_text.setString("Oh no !");
}

void Gui::show_start_menu()
{
	m_text.setCharacterSize(13);
	m_activated = true;
	m_text.setString("Press arrow keys to make Inclo grow !");
}

bool Gui::can_play() const
{
	return !m_activated;
}

void Gui::draw(sf::RenderWindow &window, unsigned int x, unsigned int y)
{
	if(m_activated)
	{
		m_text.setPosition(x - m_text.getGlobalBounds().width/2, y - m_text.getGlobalBounds().height/2);
		window.draw(m_text);	
	}
}

void Gui::close()
{
	m_activated = false;
}
