#include "Money.h"

bool Money::m_register = FactoryStatic::registerIt('%',
	[]()->std::shared_ptr<StaticIcon> {return std::make_unique<Money>(); });

Money::Money()
{
	m_sprite.setTexture(*(FileManager::getInstance().getIconTexture(MONEY)));

	m_sprite.setScale(sf::Vector2f(((float)P_SIZE / m_sprite.getGlobalBounds().height),
		((float)P_SIZE / m_sprite.getGlobalBounds().height)));
}

Money::~Money()
{
}

void Money::draw(sf::RenderWindow & window, sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
	window.draw(m_sprite);
}
