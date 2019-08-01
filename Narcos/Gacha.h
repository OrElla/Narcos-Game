#pragma once
#include "Player.h"
class Gacha : public Player
{
public:
	Gacha();
	void draw(sf::RenderWindow &window, sf::Vector2f pos); //change to player draw

	~Gacha();
private:

};

