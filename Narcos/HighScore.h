#pragma once
#include "Command.h"

class HighScore : public Command
{
public:
	HighScore();
	void add(std::string, std::unique_ptr<Command>);
	void execute(sf::RenderWindow&) override;

private:
	typedef std::pair<std::string, std::unique_ptr<Command>> option;
	std::vector<option> m_options;
	std::vector < sf::Sprite> m_sprites;
	sf::Sprite m_sprite[LOGO_BACK];
	sf::Font font;
	sf::Text listScore[TOP_5];
	int m_tableScore[NUM_OF_HS];
	void getUpdatedScore(int m_tableScore[]);

};
