#include "TNT.h"

bool TNT::m_register = FactoryStatic::registerIt('T',
	[]()->std::shared_ptr<StaticIcon> {return std::make_unique<TNT>(); });


TNT::TNT()
{
	m_sprite.setTexture(*(FileManager::getInstance().getIconTexture(TNt)));

	m_sprite.setScale(sf::Vector2f(((float)P_SIZE / m_sprite.getGlobalBounds().height),
		((float)P_SIZE / m_sprite.getGlobalBounds().height)));
}


void TNT::draw(sf::RenderWindow & window, sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
	window.draw(m_sprite);
}

TNT::~TNT()
{
}
