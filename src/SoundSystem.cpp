#include "../include/SoundSystem.h"

SoundSystem::SoundSystem(std::string music_path, std::string eat_sound_path, std::string hurt_sound_path)
{
	m_background_music.openFromFile(music_path);

	m_background_music.setLoop(true);
	m_background_music.setVolume(20);
	m_background_music.play();

	m_eat_sound_buffer.loadFromFile(eat_sound_path);
	m_hurt_sound_buffer.loadFromFile(hurt_sound_path);

	m_eat_sound.setBuffer(m_eat_sound_buffer);
	m_hurt_sound.setBuffer(m_hurt_sound_buffer);
}

void SoundSystem::play_eat_sound()
{
	m_eat_sound.play();
}

void SoundSystem::play_hurt_sound()
{
	m_hurt_sound.play();
}
