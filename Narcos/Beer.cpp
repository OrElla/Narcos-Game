#include "Beer.h"

//--------------------------------------------------------

bool Beer::m_register = FactoryStatic::registerIt('B',
	[]()->std::shared_ptr<StaticIcon> {return std::make_unique<Beer>(); });

//--------------------------------------------------------

Beer::Beer()
{
	m_sprite.setTexture(*(FileManager::getInstance().getIconTexture(BEER)));

	m_sprite.setScale(sf::Vector2f(((float)P_SIZE / m_sprite.getGlobalBounds().height),
		((float)P_SIZE / m_sprite.getGlobalBounds().height)));
}

//--------------------------------------------------------
void Beer::draw(sf::RenderWindow & window, sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
	window.draw(m_sprite);
}
//--------------------------------------------------------

Beer::~Beer()
{
}
