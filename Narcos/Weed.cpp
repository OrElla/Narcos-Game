#include "Weed.h"

bool Weed::m_register = FactoryStatic::registerIt('W',
	[]()->std::shared_ptr<StaticIcon> {return std::make_unique<Weed>(); });

Weed::Weed()
{
	m_sprite.setTexture(*(FileManager::getInstance().getIconTexture(WEED)));

	m_sprite.setScale(sf::Vector2f(((float)P_SIZE / m_sprite.getGlobalBounds().height),
		((float)P_SIZE / m_sprite.getGlobalBounds().height)));
}


Weed::~Weed()
{
}

void Weed::draw(sf::RenderWindow & window, sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
	window.draw(m_sprite);
}
