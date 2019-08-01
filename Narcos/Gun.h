#pragma once
#include "Collectable.h"
#include "FactoryStatic.h"




class Gun : public Collectable
{
public:
	Gun();
	~Gun();

	void draw(sf::RenderWindow &window, sf::Vector2f pos);	
	
private:
	static bool m_register;

};

