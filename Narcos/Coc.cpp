#include "Coc.h"


bool Coc::m_register = FactoryStatic::registerIt('!',
	[]()->std::shared_ptr<StaticIcon> {return std::make_unique<Coc>(); });


Coc::Coc()
{
	m_sprite.setTexture(*(FileManager::getInstance().getIconTexture(COC)));

	m_sprite.setScale(sf::Vector2f(((float)P_SIZE / m_sprite.getGlobalBounds().height),
		((float)P_SIZE / m_sprite.getGlobalBounds().height)));
}

void Coc::draw(sf::RenderWindow & window, sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
	window.draw(m_sprite);
}
Coc::~Coc()
{
}
