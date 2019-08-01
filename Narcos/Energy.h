#pragma once
#include "Collectable.h"
#include "FactoryStatic.h"

class Energy : public Collectable
{
public:
	Energy();
	void draw(sf::RenderWindow &window, sf::Vector2f pos);

private:
	static bool m_register;
};

