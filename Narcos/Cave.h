#pragma once
#include "FactoryStatic.h"
#include "StaticIcon.h"

class Cave : public StaticIcon
{
public:
	Cave();

	void draw(sf::RenderWindow &window, sf::Vector2f pos);
	~Cave();	

private:
	static bool m_register;
};

