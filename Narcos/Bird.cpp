#include "Bird.h"
#include "Ground1.h"
#include "Level.h"
#include "Pablo.h"
#include "Bullet.h"


bool Bird::m_register = FactoryDynamic::registerIt('Q',
	[]()->std::shared_ptr<DynamicIcon> {return std::make_unique<Bird>(); });

Bird::Bird()
{
	m_sprite.setTexture(*(FileManager::getInstance().getBirdTexture(Bird3)));
	m_sprite.setScale(sf::Vector2f(1.5*((float)P_SIZE / m_sprite.getGlobalBounds().height),
		1.5*((float)P_SIZE / m_sprite.getGlobalBounds().height)));
}


Bird::~Bird()
{
}

void Bird::getPosition(sf::Vector2f new_pos)
{
	m_pos = new_pos;
}

void Bird::SetPosition(sf::Vector2f new_pos)
{
	return m_sprite.setPosition(new_pos);
}

void Bird::move(sf::Clock& clock, sf::Vector2f boardSize)
{
	m_prevPos = m_sprite.getPosition();

	auto t = clock.getElapsedTime().asSeconds();
	if (clock.getElapsedTime().asSeconds() > m_switchFrame)
	{
		m_switchFrame += 0.3;
		if (m_goLeft)
		{
			//left frame
			m_firstLeftFrame ?
				m_sprite.setTexture(*(FileManager::getInstance().getBirdTexture(Bird4))) :
				m_sprite.setTexture(*(FileManager::getInstance().getBirdTexture(Bird5)));;
			m_firstLeftFrame = !m_firstLeftFrame;
		}
		else
		{
			//right frame
			m_firstRightFrame ?
				m_sprite.setTexture(*(FileManager::getInstance().getBirdTexture(Bird1)))
				: m_sprite.setTexture(*(FileManager::getInstance().getBirdTexture(Bird2)));
			m_firstRightFrame = !m_firstRightFrame;
		}

	}
	if (clock.getElapsedTime().asSeconds() >= m_switchDirection)
	{
		m_switchDirection += (rand() % 10) + 5;
		m_goLeft = !m_goLeft;
	}
	float distance = 1;
	m_goLeft ? m_sprite.move(-distance, 0) : m_sprite.move(distance, 0);

	if (outOfBoard(boardSize))
		m_sprite.setPosition(m_prevPos);
}