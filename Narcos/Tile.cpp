#include "Tile.h"

// defines all the game's objects

sf::Sprite Tile::getSprite()
{
	return m_sprite;
}

bool Tile::getExist()
{
	return m_exist;
}

void Tile::setExist(bool state)
{
	m_exist = state;
}

sf::Vector2f Tile::getPOS()
{
	return position;
}
