#pragma once
#include "Collectable.h"
#include "FactoryStatic.h"


class Beer : public Collectable
{
public:
	Beer();

	void draw(sf::RenderWindow &window, sf::Vector2f pos);


	~Beer();

private:
	static bool m_register;
};
