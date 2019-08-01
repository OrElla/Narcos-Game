#include "Coin.h"


bool Coin::m_register = FactoryStatic::registerIt('&',
	[]()->std::shared_ptr<StaticIcon> {return std::make_unique<Coin>(); });

Coin::Coin()
{
	sf::Vector2i pos;
	//pos = m_board[i][j];
	m_sprite.setTexture(*(FileManager::getInstance().getIconTexture(COIN)));
	m_sprite.setScale(sf::Vector2f(((float)P_SIZE / m_sprite.getGlobalBounds().height),
		((float)P_SIZE / m_sprite.getGlobalBounds().height)));
}

void Coin::draw(sf::RenderWindow & window, sf::Vector2f pos)
{	
		m_sprite.setPosition(pos);
		window.draw(m_sprite);
}

Coin::~Coin()
{
}
