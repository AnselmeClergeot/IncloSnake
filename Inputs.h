#include <SFML/Graphics.hpp>
#include "Direction.h"

class SoundSystem;

void read_direction(sf::Event &event, Direction &direction, Direction last_direction, SoundSystem &sounds);
