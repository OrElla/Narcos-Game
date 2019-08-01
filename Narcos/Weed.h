#pragma once
#include "Collectable.h"
#include "FactoryStatic.h"

class Weed : public Collectable
{
public:
	Weed();
	~Weed();

	void draw(sf::RenderWindow &window, sf::Vector2f pos);
private:
	static bool m_register;
};

