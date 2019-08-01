#pragma once
#include "Collectable.h"
#include "FactoryStatic.h"


class Coc : public Collectable
{
public:
	Coc();
	void draw(sf::RenderWindow &window, sf::Vector2f pos);
	~Coc();

private:
	static bool m_register;
};

