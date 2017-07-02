#include <iostream>
#include <string>
#include <fstream>

#include "../include/ScoreSystem.h"

ScoreSystem::ScoreSystem(std::string font_path, unsigned int font_size, sf::Color color)
{
	std::ifstream file("score", std::ios::in);

	if(file)
	{
		file >> m_best_score;

		file.close();
	}

	m_best_score_text.setString(std::to_string(m_best_score));

	m_font.loadFromFile(font_path);
	m_score_text.setFont(m_font);
	m_score_text.setCharacterSize(font_size);
	m_score_text.setColor(color);

	m_best_score_text.setFont(m_font);
	m_best_score_text.setCharacterSize(font_size/2);
	m_best_score_text.setColor(color);
}

void ScoreSystem::set_score(unsigned int score)
{
	m_score = score;
	m_score_text.setString(std::to_string(score));

	if(score > m_best_score)
		m_best_score = score;

	m_best_score_text.setString(std::to_string(m_best_score));
}

void ScoreSystem::draw(sf::RenderWindow &window, unsigned int x, unsigned int y, unsigned int best_score_x, unsigned int best_score_y)
{
	m_score_text.setPosition(x - m_score_text.getGlobalBounds().width/2, y - m_score_text.getGlobalBounds().height/2);
	window.draw(m_score_text);

	m_best_score_text.setPosition(best_score_x, best_score_y);
	window.draw(m_best_score_text);
}

void ScoreSystem::write_best_score()
{
	std::ofstream file("score", std::ios::out | std::ios::trunc);

	if(file)
	{
		file << m_best_score;
	
		file.close();
	}
}
