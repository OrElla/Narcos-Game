#pragma once
#include "Command.h"
class SoundIcon : public Command
{
public:
	SoundIcon();
	void add(std::string, std::unique_ptr<Command>);
	void execute(sf::RenderWindow&) override;

private:
	typedef std::pair<std::string, std::unique_ptr<Command>> option;
	std::vector<option> m_options;
	sf::Sprite m_logo;   //background
	sf::Texture m_texture; //change
	std::vector < sf::Sprite> m_sprites;
};

