#pragma once
#include "Character.h"
#include "FactoryDynamic.h"

class PoliceMan : public Character
{
public:
	PoliceMan();
	~PoliceMan();

	void getPosition(sf::Vector2f new_pos);
	void SetPosition(sf::Vector2f new_pos);
	void move(sf::Clock& clock, sf::Vector2f boardSize);
	void setcanshoot(bool state);
	bool getcanshoot();
private:
	bool canshoot;
	double m_switchDirection = (rand() % 10) + 5;
	double m_switchFrame = 0.3;
	static bool m_register;
	bool m_firstLeftFrame = true;
	bool m_firstRightFrame = true;
	float m_speed = 5;
};

