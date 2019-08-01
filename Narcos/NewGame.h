#pragma once
#include "Command.h"

class NewGame : public Command
{
public:
	NewGame();
	~NewGame();

	void execute(sf::RenderWindow&) override;

private:
	sf::Sprite m_back;
};