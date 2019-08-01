#pragma once
#include "Collectable.h"
#include "FactoryStatic.h"

class Food : public Collectable
{
public:
	Food();
	~Food();
	void draw(sf::RenderWindow &window, sf::Vector2f pos);

private:
	static bool m_register;
};

