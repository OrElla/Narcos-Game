#pragma once
#pragma once
#include <SFML\Graphics.hpp>
#include "FileManager.h"
const int N = 5;

class PlayerState
{
public:
	PlayerState();
	~PlayerState() {};
	void draw(sf::RenderWindow & window, int life, int score, int level,
		sf::Vector2f BoardSize,
		int tnt, int food, int gun, int coc, int knife, int energy);

private:
	sf::Text m_statusBar;
	sf::Text m_statusBar2[N];
	sf::Text m_energyBar;

	sf::Font m_font;
	static sf::Texture t;
	sf::Sprite m_lifeSprite;
	sf::Sprite m_sprites[NUM_OF_IM];
	sf::Sprite energies;

};

