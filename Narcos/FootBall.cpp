#include "FootBall.h"
#include "Level.h"

bool FootBall::m_register = FactoryDynamic::registerIt('?',
	[]()->std::shared_ptr<DynamicIcon> {return std::make_unique<FootBall>(); });

FootBall::FootBall()
{
	m_sprite.setTexture(*(FileManager::getInstance().getIconTexture(FOOTBALL)));

	m_sprite.setOrigin(getCenter(m_sprite.getPosition()));
	SetPosition(m_sprite.getOrigin());
}

void FootBall::draw(sf::RenderWindow & window, float passedTime)
{
	window.draw(m_sprite);
}
void FootBall::move(float passedTime, sf::Vector2f boardSize)
{
	float distance = 500 * m_speed * passedTime;
	m_sprite.move(distance, 0);

	m_pos = m_sprite.getPosition();
}

void FootBall::SetPosition(sf::Vector2f new_pos)
{
	m_sprite.setPosition(getCenter(new_pos));

}

FootBall::~FootBall()
{
}
