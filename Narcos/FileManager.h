#pragma once

#include <fstream>
#include <memory>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include "Tile.h"

using std::ifstream;
using std::string;

const int NUM_OF_SOUNDS = 30; //change
const int NUM_OF_SCREENS =30; //change
const int NUM_OF_ICONS = 4; //change
const int NUM_OF_FONTS = 2;//change
const int NUM_OF_HS = 5;
const int NUM_OF_OPTIONS = 15;
const int NUM_OF_IM = 50;
const int NUM_OF_BIRDS = 6;
const int NUM_OF_LIONS = 6;
const int NUM_OF_WOLFS = 6;
const int NUM_OF_GACHA = 8;
const int NUM_OF_PCM = 8;


struct high_score {
	int score;
	std::string name;
};


class FileManager
{
public:

	static FileManager & getInstance();

	const std::vector<high_score>& loadHighScore();
	void updateScore(string, int);
	sf::Texture * getIconTexture(size_t shape);
	sf::Texture * getPlayerTexture(size_t shape);
	sf::Texture * getPlayer2Texture(size_t shape);
	sf::Texture * getPoliceManTexture(size_t shape);
	sf::Texture * getBirdTexture(size_t shape);
	sf::Texture * getWolfTexture(size_t shape);
	sf::Texture * getLionTexture(size_t shape);
	sf::Texture * getButtonTexture(size_t shape);


	sf::SoundBuffer * getGameSound(size_t type);
	sf::Texture * getScreen(size_t screen);
	sf::Font * getFont(size_t type);


	//sf::SoundBuffer * getPlayerSound(size_t type);

	sf::Texture * getLifeTexture();
	~FileManager();
private:
	FileManager();
	std::vector<high_score> m_listScore;
	sf::Font m_font[NUM_OF_FONTS];
	sf::Texture m_lifeCount;
	sf::Texture m_pTexture[NUM_OF_IM];
	sf::Texture m_playerTexture[NUM_OF_IM];
	sf::Texture m_player2Texture[NUM_OF_GACHA];
	sf::Texture m_pcmTexture[NUM_OF_PCM];
	sf::Texture m_birdTexture[NUM_OF_BIRDS];
	sf::Texture m_lionTexture[NUM_OF_LIONS];
	sf::Texture m_wolfTexture[NUM_OF_WOLFS];

	sf::SoundBuffer m_gameSounds[NUM_OF_SOUNDS];
	sf::Texture m_pScreeen[NUM_OF_SCREENS];

	sf::Texture m_pButton[NUM_OF_OPTIONS];
	//sf::Music m_gameSounds[NUM_OF_SOUNDS - 4];

};

