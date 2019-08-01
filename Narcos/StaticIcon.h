#pragma once
#include "Tile.h"

class Level;

class StaticIcon : public Tile
{
public:
	StaticIcon();
	void setPOS(sf::Vector2f p);
	sf::Vector2f getpos();
	virtual void draw(sf::RenderWindow &window, sf::Vector2f pos) = 0;//TODO
	//virtual void collide(Tile * object, Level & m_level) {}
	~StaticIcon();
private:
	sf::Vector2f p_pos;
};

