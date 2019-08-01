#include "Energy.h"

bool Energy::m_register = FactoryStatic::registerIt('E',
	[]()->std::shared_ptr<StaticIcon> {return std::make_unique<Energy>(); });


Energy::Energy()
{
	m_sprite.setTexture(*(FileManager::getInstance().getIconTexture(ENERGY)));

	m_sprite.setScale(sf::Vector2f(((float)P_SIZE / m_sprite.getGlobalBounds().height),
		((float)P_SIZE / m_sprite.getGlobalBounds().height)));
}

void Energy::draw(sf::RenderWindow & window, sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
	window.draw(m_sprite);
}


