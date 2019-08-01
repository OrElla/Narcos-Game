#pragma once
#include "FactoryStatic.h"
#include "StaticIcon.h"

class Ground1 : public StaticIcon
{
public:
	Ground1();

	void draw(sf::RenderWindow &window, sf::Vector2f pos);
	~Ground1();
//	virtual void collide(Demon * object, Level & m_level);
private:
	static bool m_register;
};



