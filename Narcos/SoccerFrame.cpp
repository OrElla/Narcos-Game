#include "SoccerFrame.h"

//bool SoccerFrame::m_register = FactoryStatic::registerIt('Q',
	//[]()->std::unique_ptr<StaticIcon> {return std::make_unique<SoccerFrame>(); });

SoccerFrame::SoccerFrame()
{
	//m_sprite.setTexture(*(FileManager::getInstance().getIconTexture(SOCCER_FRAME)));

	//m_sprite.setScale(sf::Vector2f(((float)P_SIZE / m_sprite.getGlobalBounds().height),
		//((float)P_SIZE / m_sprite.getGlobalBounds().height)));
}
/*
void SoccerFrame::draw(sf::RenderWindow & window, sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
	window.draw(m_sprite);
}
*/

SoccerFrame::~SoccerFrame()
{
}
