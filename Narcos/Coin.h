#pragma once
#include "Collectable.h"
#include "FactoryStatic.h"



class Coin : public Collectable
{
public:
	Coin();
	void draw(sf::RenderWindow &window, sf::Vector2f pos);
	~Coin();

private:
	static bool m_register;
};

