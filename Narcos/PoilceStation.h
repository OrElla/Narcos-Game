#pragma once
#include "StaticIcon.h"
#include "FactoryStatic.h"

class PoilceStation : public StaticIcon
{
public:
	PoilceStation();
	~PoilceStation();
	void draw(sf::RenderWindow &window, sf::Vector2f pos);

private:
	static bool m_register;
};

