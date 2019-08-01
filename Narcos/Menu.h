#pragma once
#include "Command.h"

class Menu
{
public:
	Menu();
	void add(std::string, std::unique_ptr<Command>);
	void activate();
	void execute(sf::RenderWindow&);


private:
	typedef std::pair<std::string, std::unique_ptr<Command>> option;
	std::vector<option> m_options;
	sf::RenderWindow m_window;
	sf::Music m_sound;

	std::vector < sf::Sprite> m_sprites;
	sf::Sprite m_sprite[LOGO_BACK];
};

