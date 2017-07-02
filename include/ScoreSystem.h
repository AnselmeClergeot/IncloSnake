#include <SFML/Graphics.hpp>

class ScoreSystem
{
	public :
		ScoreSystem(std::string font_path, unsigned int font_size, sf::Color color);

		void set_score(unsigned int score);

		void draw(sf::RenderWindow &window, unsigned int x, unsigned int y, unsigned int best_score_x, unsigned int best_score_y);

		void write_best_score();

	private :
		unsigned int m_score, m_best_score;
		sf::Font m_font;
		sf::Text m_score_text, m_best_score_text;

};
