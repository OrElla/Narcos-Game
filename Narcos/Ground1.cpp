#include "Ground1.h"

bool Ground1::m_register = FactoryStatic::registerIt('#',
	[]()->std::shared_ptr<StaticIcon> {return std::make_unique<Ground1>(); });

Ground1::Ground1()
{

	m_sprite.setTexture(*(FileManager::getInstance().getIconTexture(GROUND)));
	m_sprite.setScale(sf::Vector2f(((float)P_SIZE / m_sprite.getGlobalBounds().height),
		((float)P_SIZE / m_sprite.getGlobalBounds().height)));


}

void Ground1::draw(sf::RenderWindow & window, sf::Vector2f pos)
{
		m_sprite.setPosition(pos);
		window.draw(m_sprite);
}

Ground1::~Ground1()
{
}

