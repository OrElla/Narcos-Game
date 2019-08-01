#pragma once
#include "Command.h"

class GameOverDead : public Command
{
public:
	GameOverDead();
	void add(std::string, std::unique_ptr<Command>);
	void execute(sf::RenderWindow&) override;

private:
	typedef std::pair<std::string, std::unique_ptr<Command>> option;
	std::vector<option> m_options;
	std::vector < sf::Sprite> m_sprites;
	sf::Sprite m_sprite[LOGO_BACK+1];
};

