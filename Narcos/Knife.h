#pragma once
#include "Collectable.h"
#include "FactoryStatic.h"

class Knife : public Collectable
{
public:
	Knife();
	void draw(sf::RenderWindow &window, sf::Vector2f pos);	
	~Knife();

private:
	static bool m_register;
};

