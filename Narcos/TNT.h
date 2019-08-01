#pragma once
#include "Collectable.h"
#include "FactoryStatic.h"

class TNT : public Collectable
{
public:
	TNT();
	void draw(sf::RenderWindow &window, sf::Vector2f pos);	
	~TNT();

private:
	static bool m_register;
	sf::Vector2f p_pos;
};

