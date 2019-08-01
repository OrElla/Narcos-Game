#pragma once
#include "Collectable.h"
#include "FactoryStatic.h"

class Money : public Collectable 
{
public:
	Money();
	~Money();
	void draw(sf::RenderWindow &window, sf::Vector2f pos);

private:
	static bool m_register;
};

