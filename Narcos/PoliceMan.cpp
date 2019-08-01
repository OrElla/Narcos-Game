#include "PoliceMan.h"
#include "Ground1.h"
#include "Level.h"
#include "Pablo.h"
#include "Bullet.h"

// inherites from enemy 
// can shot, and move from side to side

bool PoliceMan::m_register = FactoryDynamic::registerIt('P',
	[]()->std::shared_ptr<DynamicIcon> {return std::make_unique<PoliceMan>(); });

PoliceMan::PoliceMan()
{
	m_sprite.setTexture(*(FileManager::getInstance().getPoliceManTexture(PO1)));
}


PoliceMan::~PoliceMan()
{
}

void PoliceMan::getPosition(sf::Vector2f new_pos)
{
	m_pos = new_pos;
}

void PoliceMan::SetPosition(sf::Vector2f new_pos)
{
	return m_sprite.setPosition(new_pos);
}
// move the policman
void PoliceMan::move(sf::Clock& clock, sf::Vector2f boardSize)
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
				m_sprite.setTexture(*(FileManager::getInstance().getPoliceManTexture(PO1))):
				m_sprite.setTexture(*(FileManager::getInstance().getPoliceManTexture(PO3)));;
			m_firstLeftFrame = !m_firstLeftFrame;
		}
		else
		{
			//right frame
			m_firstRightFrame ? 
				m_sprite.setTexture(*(FileManager::getInstance().getPoliceManTexture(PO2)))
				: m_sprite.setTexture(*(FileManager::getInstance().getPoliceManTexture(PO6)));
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

void PoliceMan::setcanshoot(bool state)
{
	canshoot = state;
}

bool PoliceMan::getcanshoot()
{
	return canshoot;
}

