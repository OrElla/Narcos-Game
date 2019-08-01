#pragma once
#include "Command.h"
#include "HighScore.h"
class EnterScore : public Command
{
public:
	EnterScore();
	void add(std::string, std::unique_ptr<Command>);
	void execute(sf::RenderWindow&) override;
	Enter_ID getEhsButton(sf::Vector2i buttonPos);
	void listHs(sf::RenderWindow &window);


private:
	int m_screenScore;
	typedef std::pair<std::string, std::unique_ptr<Command>> option;
	std::vector<option> m_options;
	std::vector < sf::Sprite> m_sprites;
	sf::Sprite m_sprite[LOGO_BACK];
	HighScore h;
	sf::Font font;


};

