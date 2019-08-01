#include "Dea.h"



//inherites from enemy 
// can shot, and move from side to side
Dea::Dea()
{
}


Dea::~Dea()
{
}

void Dea::SetPosition(sf::Vector2f new_pos)
{
	m_sprite.setPosition(getCenter(new_pos));

}


