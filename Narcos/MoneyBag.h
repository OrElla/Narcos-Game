#pragma once
#include "Collectable.h"
#include "FactoryStatic.h"

class MoneyBag : public Collectable
{
public:
	MoneyBag();
	void draw(sf::RenderWindow &window, sf::Vector2f pos);
	~MoneyBag();

private:
	static bool m_register;
};

