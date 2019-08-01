#include "PoilceStation.h"

bool PoilceStation::m_register = FactoryStatic::registerIt('^',
	[]()->std::shared_ptr<StaticIcon> {return std::make_unique<PoilceStation>(); });

PoilceStation::PoilceStation()
{
	m_sprite.setTexture(*(FileManager::getInstance().getIconTexture(POLICE_STATION)));

	m_sprite.setScale(sf::Vector2f(2*((float)P_SIZE / m_sprite.getGlobalBounds().height),
		2*((float)P_SIZE / m_sprite.getGlobalBounds().height)));

}

PoilceStation::~PoilceStation()
{

}

void PoilceStation::draw(sf::RenderWindow & window, sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
	window.draw(m_sprite);
}


