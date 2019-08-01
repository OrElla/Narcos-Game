#pragma once
#include "DynamicIcon.h"
#include "FactoryDynamic.h"


class FootBall : public DynamicIcon
{
public:
	FootBall();

	void draw(sf::RenderWindow &window, float passedTime);
	void move(float passedTime, sf::Vector2f boardSize);
	void SetPosition(sf::Vector2f new_pos);

	~FootBall();
private:
	static bool m_register;
	float m_speed = 5;
};

