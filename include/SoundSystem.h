#include <SFML/Audio.hpp>

class SoundSystem
{
	public :
		SoundSystem(std::string music_path, std::string eat_sound_path, std::string hurt_sound_path);

		void play_eat_sound();
		void play_hurt_sound();

	private :
		sf::Music m_background_music;
		sf::SoundBuffer m_eat_sound_buffer, m_hurt_sound_buffer;
		sf::Sound m_eat_sound, m_hurt_sound;
};
