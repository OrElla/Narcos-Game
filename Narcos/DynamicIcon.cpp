#include "DynamicIcon.h"

//defines all the Dynamic Icons : 
//player, enemies , bullets

DynamicIcon::DynamicIcon()
{
}

DynamicIcon::~DynamicIcon()
{
}

void DynamicIcon::draw(sf::RenderWindow & window, float passedTime)
{
	window.draw(m_sprite);
}





void DynamicIcon::rotatePlayer(int rotate)
{	
		m_sprite.rotate(rotate);
}
void DynamicIcon::decLife()
{
	m_life--;
}

void DynamicIcon::collideGround(const Ground1 & ground)
{
		m_sprite.setPosition(m_prevPos);
}

int DynamicIcon::getLife() const
{
	return m_life;
}

Direction_t DynamicIcon::getDirection()
{
	return m_direction;
}

sf::Vector2f DynamicIcon::getStartingPosition()
{
	return m_sprite.getPosition();
}

sf::Vector2f DynamicIcon::getPosition()
{
	return m_sprite.getPosition();
}

void DynamicIcon::setStartingPosition(sf::Vector2f pos)
{
	m_startingPosition = pos;
}

sf::Vector2f DynamicIcon::getNextDirection(Direction_t direction)
{
	sf::Vector2f nextPos = m_sprite.getPosition();

	switch (direction)
	{
	case UP:
		return sf::Vector2f(nextPos.x, nextPos.y);
	case DOWN:
		return sf::Vector2f(nextPos.x, nextPos.y + (3*P_SIZE));
	case RIGHT:
		return sf::Vector2f(nextPos.x + (3*P_SIZE), nextPos.y);
	case LEFT:
		return sf::Vector2f(nextPos.x , nextPos.y);
	}
	return sf::Vector2f(nextPos.x + (P_SIZE/2), nextPos.y);
}

bool DynamicIcon::isCentered(sf::Vector2f pos, sf::Vector2f center)
{
	return abs(pos.x - center.x) < DIFF_SIZE &&
		abs(pos.y - center.y) < DIFF_SIZE;
}

bool DynamicIcon::outOfBoard(sf::Vector2f size)
{
	int distance = P_SIZE / 2;
	return m_sprite.getPosition().x + distance > size.y ||
		m_sprite.getPosition().y + distance > size.x ||
		m_sprite.getPosition().x - distance < 0 ||
		m_sprite.getPosition().y - distance < 0;
}

sf::Vector2f DynamicIcon::getCenter(sf::Vector2f pos)
{
	sf::Vector2f newPos;

	newPos.x = (pos.x - ((int)pos.x % P_SIZE)) + P_SIZE / 2;
	newPos.y = (pos.y - ((int)pos.y % P_SIZE)) + P_SIZE / 2;
	return newPos;
}
