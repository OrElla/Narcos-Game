#pragma once
#include "DynamicIcon.h"
#include "Stabing.h"
#include "Bomb.h"
#include "PlayerMove.h"
#include "Shooting.h"
#include "State.h"
#include "StandingState.h"

class Player : public DynamicIcon
{
public:
	Player();
	~Player();

private:
	int m_points;
	int m_itemCollected;
	sf::Sound m_sounds[NUM_OF_SOUNDS - 2];

};

