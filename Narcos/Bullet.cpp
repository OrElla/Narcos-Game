#include "Bullet.h"
#include "Pablo.h"
#include "PoliceMan.h"


bool Bullet::m_register = FactoryDynamic::registerIt('~',
	[]()->std::shared_ptr<DynamicIcon> {return std::make_unique<Bullet>(); });

Bullet::Bullet()
{
	m_sprite.setTexture(*(FileManager::getInstance().getIconTexture(BULLET)));

	m_sprite.setScale(sf::Vector2f(((float)P_SIZE / m_sprite.getGlobalBounds().height),
		((float)P_SIZE / m_sprite.getGlobalBounds().height)));

	m_sprite.setOrigin(getCenter(m_sprite.getPosition()));
	SetPosition(m_sprite.getOrigin());
}


void Bullet::getPosition(sf::Vector2f pos)
{
	m_pos = pos;
}

void Bullet::SetPosition(sf::Vector2f new_pos)
{
	m_sprite.setPosition(getCenter(new_pos));
}

void Bullet::move(sf::Clock& clock, sf::Vector2f boardSize)
{
	float distance = 5;
	m_sprite.move(distance, 0);

	m_pos = m_sprite.getPosition();

}

void Bullet::draw(sf::RenderWindow & window, float passedTime)
{
	window.draw(m_sprite);
}

Bullet::~Bullet()
{
}


