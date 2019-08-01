#include "StaticIcon.h"


StaticIcon::StaticIcon()
{
}

void StaticIcon::setPOS(sf::Vector2f p)
{
	p_pos = p;
}

sf::Vector2f StaticIcon::getpos()
{
	return p_pos;
}

StaticIcon::~StaticIcon()
{
}