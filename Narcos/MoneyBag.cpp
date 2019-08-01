#include "MoneyBag.h"


bool MoneyBag::m_register = FactoryStatic::registerIt('$',
	[]()->std::shared_ptr<StaticIcon> {return std::make_unique<MoneyBag>(); });

MoneyBag::MoneyBag()
{
	m_sprite.setTexture(*(FileManager::getInstance().getIconTexture(MONEY_BAG)));

	m_sprite.setScale(sf::Vector2f(((float)P_SIZE / m_sprite.getGlobalBounds().height),
		((float)P_SIZE / m_sprite.getGlobalBounds().height)));
}

void MoneyBag::draw(sf::RenderWindow & window, sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
	window.draw(m_sprite);
}

MoneyBag::~MoneyBag()
{
}
