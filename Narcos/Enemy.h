#pragma once
#include "DynamicIcon.h"
#include "S2sMove.h"


class Enemy : public DynamicIcon
{
public:
	Enemy();
	~Enemy();
	void changeDirection();
	bool goesleft();

protected:
	bool m_goLeft = false;
};
