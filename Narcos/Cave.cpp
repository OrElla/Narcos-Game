#include "Cave.h"


//cave class - Bonus level

//--------------------------------------------------------

bool Cave::m_register = FactoryStatic::registerIt('C',
	[]()->std::shared_ptr<StaticIcon> {return std::make_unique<Cave>(); });
//--------------------------------------------------------

Cave::Cave()
{
	m_sprite.setTexture(*(FileManager::getInstance().getIconTexture(CAVE)));

	m_sprite.setScale(sf::Vector2f(2*((float)P_SIZE / m_sprite.getGlobalBounds().height),
		2*((float)P_SIZE / m_sprite.getGlobalBounds().height)));
}
//--------------------------------------------------------

void Cave::draw(sf::RenderWindow & window, sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
	window.draw(m_sprite);
}

Cave::~Cave()
{
}
