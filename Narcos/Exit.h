#pragma once
#include "Command.h"

class Exit : public Command
{
public:
	Exit();
	~Exit();

	void execute(sf::RenderWindow&) override;

private:
};

