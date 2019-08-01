#pragma once
#include "DynamicIcon.h"
#include "MoveStraight.h"
#include "FactoryDynamic.h"



class Bullet : public DynamicIcon
{
public:
	Bullet();

	void getPosition(sf::Vector2f new_pos);
	void SetPosition(sf::Vector2f new_pos);

	void move(sf::Clock& clock, sf::Vector2f boardSize);
	void draw(sf::RenderWindow &window, float passedTime);

	~Bullet();

private:
	static bool m_register;
	float m_speed = 5;
};

