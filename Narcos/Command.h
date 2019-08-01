#pragma once
#include <SFML\Graphics.hpp>
#include "FileManager.h"
#include <memory>

class Command
{
public:
	virtual void execute(sf::RenderWindow&) = 0;

};

