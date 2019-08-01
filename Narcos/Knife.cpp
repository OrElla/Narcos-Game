#include "Knife.h"

bool Knife::m_register = FactoryStatic::registerIt('K',
	[]()->std::shared_ptr<StaticIcon> {return std::make_unique<Knife>(); });

Knife::Knife()
{
	m_sprite.setTexture(*(FileManager::getInstance().getIconTexture(KNIFE)));

	m_sprite.setScale(sf::Vector2f(((float)P_SIZE / m_sprite.getGlobalBounds().height),
		((float)P_SIZE / m_sprite.getGlobalBounds().height)));
}

void Knife::draw(sf::RenderWindow & window, sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
	window.draw(m_sprite);
}


Knife::~Knife()
{
}
