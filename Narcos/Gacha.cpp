#include "Gacha.h"

// second player opption
Gacha::Gacha() 
{
	m_sprite.setTexture(*(FileManager::getInstance().getIconTexture(GACHA)));

	m_sprite.setScale(sf::Vector2f(((float)P_SIZE / m_sprite.getGlobalBounds().height),
		((float)P_SIZE / m_sprite.getGlobalBounds().height)));
}

void Gacha::draw(sf::RenderWindow & window, sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
	window.draw(m_sprite);
}



Gacha::~Gacha()
{
}
