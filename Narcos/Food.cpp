#include "Food.h"

bool Food::m_register = FactoryStatic::registerIt('*',
	[]()->std::shared_ptr<StaticIcon> {return std::make_unique<Food>(); });

Food::Food()
{
	m_sprite.setTexture(*(FileManager::getInstance().getIconTexture(FOOD)));

	m_sprite.setScale(sf::Vector2f(((float)P_SIZE / m_sprite.getGlobalBounds().height),
		((float)P_SIZE / m_sprite.getGlobalBounds().height)));
}


Food::~Food()
{
}

void Food::draw(sf::RenderWindow & window, sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
	window.draw(m_sprite);
}
