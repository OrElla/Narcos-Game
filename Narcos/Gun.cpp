#include "Gun.h"

bool Gun::m_register = FactoryStatic::registerIt('G',
	[]()->std::shared_ptr<StaticIcon> {return std::make_unique<Gun>(); });

Gun::Gun()
{
	m_sprite.setTexture(*(FileManager::getInstance().getIconTexture(GUN)));

	m_sprite.setScale(sf::Vector2f(((float)P_SIZE / m_sprite.getGlobalBounds().height),
		((float)P_SIZE / m_sprite.getGlobalBounds().height)));
}


Gun::~Gun()
{
}

void Gun::draw(sf::RenderWindow & window, sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
	window.draw(m_sprite);
}

