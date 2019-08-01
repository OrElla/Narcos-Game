#include "Enemy.h"


// defines the enemy : policeman, dea, animals
Enemy::Enemy()
{
}
Enemy::~Enemy()
{
}
void Enemy::changeDirection()
{
	m_goLeft = !m_goLeft;
}

bool Enemy::goesleft()
{
	return m_goLeft;
}
