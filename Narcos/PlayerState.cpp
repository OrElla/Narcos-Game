#include "PlayerState.h"


PlayerState::PlayerState()
{
	m_font = *(FileManager::getInstance().getFont(GAME_FONT));
	m_statusBar.setFont(m_font);
	for(int i =0 ; i< N ; i++)
		m_statusBar2[i].setFont(m_font);

	m_energyBar.setFont(m_font);

	m_lifeSprite.setTexture(*(FileManager::getInstance().getIconTexture(WEED)));
	//m_lifeSpirte.setTextureRect(sf::IntRect(11 * P_SIZE, 0, P_SIZE, P_SIZE));
	m_lifeSprite.setScale(sf::Vector2f(((float)P_SIZE / m_lifeSprite.getGlobalBounds().height),
		((float)P_SIZE / m_lifeSprite.getGlobalBounds().height)));

	m_sprites[FOOD].setTexture(*(FileManager::getInstance().getIconTexture(FOOD)));
	m_sprites[COC].setTexture(*(FileManager::getInstance().getIconTexture(COC)));
	m_sprites[GUN].setTexture(*(FileManager::getInstance().getIconTexture(GUN)));
	m_sprites[TNt].setTexture(*(FileManager::getInstance().getIconTexture(TNt)));
	m_sprites[KNIFE].setTexture(*(FileManager::getInstance().getIconTexture(KNIFE)));
	energies.setTexture(*(FileManager::getInstance().getIconTexture(ENERGY)));


}

void PlayerState::draw(sf::RenderWindow & window, int life, int score, int level,
	sf::Vector2f BoardSize,int tnt , int food, int gun ,
	int coc, int knife,int energy)
{
	std::string status = "SCORE " + std::to_string(score) +
		"   LEVEL " + std::to_string(level) + "   LIFE  ";
	m_statusBar.setPosition(BoardSize.x + 5.f, 0);
	m_statusBar.setString(status);
	m_statusBar.setCharacterSize(P_SIZE);
	window.draw(m_statusBar);

	for (int i = 0; i < life; i++){
		m_lifeSprite.setPosition(BoardSize.x + 270.f + 10 + i * P_SIZE, 0);
		window.draw(m_lifeSprite);
	}

	m_sprites[GUN].setPosition(BoardSize.x + 5.f + 0 * P_SIZE, 35);
	m_sprites[TNt].setPosition(BoardSize.x + 5.f + 30 + 1 * P_SIZE, 35);
	m_sprites[COC].setPosition(BoardSize.x + 5.f + 40 + 3 * P_SIZE, 35);
	m_sprites[FOOD].setPosition(BoardSize.x + 5.f + 70 + 4 * P_SIZE, 35);
	energies.setPosition(BoardSize.x + 5.f + 80 + 6 * P_SIZE, 35);


	std::string str2;
	for (int i = 0; i < N; i++)
	{
		m_statusBar2[i].setCharacterSize(P_SIZE);

		switch (i)
		{
		case 0:
		{
			str2 = "     " + std::to_string(gun);
			m_statusBar2[i].setString(str2);
		}
		case 1:
		{
			str2 = "     " + std::to_string(tnt);
			m_statusBar2[i].setString(str2);
		}
		case 2:
		{
			str2 = "     " + std::to_string(coc);
			m_statusBar2[i].setString(str2);
		}
		case 3:
		{
			str2 = "     " + std::to_string(food);
			m_statusBar2[i].setString(str2);
		}
		case 4:
		{
			str2 = "     " + std::to_string(knife);
			m_statusBar2[i].setString(str2);
		}
		}
	}


	if (gun > 0) {
		m_statusBar2[0].setPosition(m_sprites[GUN].getPosition().x - 0.5f,
			m_sprites[GUN].getPosition().y);
		window.draw(m_statusBar2[0]);
		window.draw(m_sprites[GUN]);
	}
	if (tnt > 0) {
		m_statusBar2[1].setPosition(m_sprites[TNt].getPosition().x - 0.5f,
			m_sprites[TNt].getPosition().y);
		window.draw(m_statusBar2[1]);
		window.draw(m_sprites[TNt]);
	}
	if (coc > 0) {
		m_statusBar2[2].setPosition(m_sprites[COC].getPosition().x - 0.5f,
			m_sprites[COC].getPosition().y);
		window.draw(m_statusBar2[2]);
		window.draw(m_sprites[COC]);
	}

	if (food > 0) {
		m_statusBar2[3].setPosition(m_sprites[FOOD].getPosition().x - 0.5f,
			m_sprites[FOOD].getPosition().y);
		window.draw(m_statusBar2[3]);
		window.draw(m_sprites[FOOD]);
	}
	if (knife > 0) {
		m_statusBar2[4].setPosition(m_sprites[KNIFE].getPosition().x - 0.5f,
			m_sprites[KNIFE].getPosition().y);
		window.draw(m_statusBar2[4]);
		window.draw(m_sprites[KNIFE]);
	}


	std::string str3 = "ENERGY   ";
	m_energyBar.setPosition(BoardSize.x + 5.f + 0 * P_SIZE, 75);
	m_energyBar.setString(str3);
	m_energyBar.setCharacterSize(P_SIZE);

	if (energy > 0)
	{
		window.draw(m_energyBar);

		for (int i = 0; i < energy; i++)
		{
			energies.setPosition(m_energyBar.getPosition().x + 90 + i * P_SIZE,
				m_energyBar.getPosition().y+5);
			window.draw(energies);
		}
	}
}

