#include "FileManager.h"

// singelton class  - resource manager

FileManager::FileManager()
{
	//Characters 

	//defies all the characters..
	std::string a = "images/pablo/p";
	for(int i =0;i<int(P26);++i)
		m_playerTexture[Pablo_p(i)].loadFromFile(a + std::to_string(i+1)+".png");

	std::string b = "images/PoliceMan/po";
	for (int i = 0; i<int(8); ++i)
		m_pcmTexture[PoliceMan_po(i)].loadFromFile(b + std::to_string(i + 1) + ".png");

	std::string c = "images/gacha/g";
	for (int i = 0; i<int(8); ++i)
		m_player2Texture[Gacha_g(i)].loadFromFile(c + std::to_string(i + 1) + ".png");

	std::string d = "images/animal/bird";
	for (int i = 0; i<int(Bird6); ++i)
		m_birdTexture[Bird_b(i)].loadFromFile(d + std::to_string(i + 1) + ".png");

	std::string e = "images/animal/lion";
	for (int i = 0; i<int(6); ++i)
		m_lionTexture[Lion_l(i)].loadFromFile(e + std::to_string(i + 1) + ".png");

	std::string f = "images/animal/wolf";
	for (int i = 0; i<int(6); ++i)
		m_wolfTexture[Wolf_w(i)].loadFromFile(f + std::to_string(i + 1) + ".png");




	//static objects - collision
	m_pTexture[POLICE_STATION].loadFromFile("images/ps64.png");
	m_pTexture[CAVE].loadFromFile("images/cave64.png");
	m_pTexture[GROUND].loadFromFile("images/m_ground3.jpg");

	//collectable
	m_pTexture[COIN].loadFromFile("images/coin.png");
	m_pTexture[MONEY].loadFromFile("images/money.png");
	m_pTexture[MONEY_BAG].loadFromFile("images/money_bag.png");
	m_pTexture[COC].loadFromFile("images/coc.png");
	m_pTexture[WEED].loadFromFile("images/weed.png");
	m_pTexture[GUN].loadFromFile("images/gun.png");
	m_pTexture[KNIFE].loadFromFile("images/knife.png");
	m_pTexture[TNt].loadFromFile("images/tnt.png");
	m_pTexture[BEER].loadFromFile("images/beer.png");
	m_pTexture[SPECIAL_BEER].loadFromFile("images/beerSpecial.png");
	m_pTexture[FOOTBALL].loadFromFile("images/football.png");
	m_pTexture[SOCCER_FRAME].loadFromFile("images/soccer_frame.png"); //change
	m_pTexture[GOAL_T].loadFromFile("images/goal.png");
	m_pTexture[BLOOD].loadFromFile("images/blood.png");
	m_pTexture[EXPLOSION].loadFromFile("images/explosion.jpg");


	m_pTexture[BULLET].loadFromFile("images/b2.png"); 
	m_pTexture[ENERGY].loadFromFile("images/energy.png"); 
	m_pTexture[FOOD].loadFromFile("images/Food/burger.png");


	//sound
	m_gameSounds[PLATO_O_PLOMO].loadFromFile("sounds/plataOplomo.wav");
	m_gameSounds[SMOKING].loadFromFile("sounds/smoking.wav");
	m_gameSounds[SNIFFING].loadFromFile("sounds/sniffing.wav");
	m_gameSounds[COINS].loadFromFile("sounds/coin.wav");
	m_gameSounds[MONEY_s].loadFromFile("sounds/money.wav");
	m_gameSounds[MONEY_BAG_s].loadFromFile("sounds/moneyBag.wav");
	m_gameSounds[KNIFE_SOUND].loadFromFile("sounds/knife_sound.wav");
	m_gameSounds[EATING_SOUND].loadFromFile("sounds/eat.wav");
	m_gameSounds[BULLETS_SOUND].loadFromFile("sounds/gun_sound.wav");
	m_gameSounds[EVIL_SOUND].loadFromFile("sounds/evil.wav");
	m_gameSounds[HIJO_DE_PUTA].loadFromFile("sounds/hijo_de_puta.wav");
	m_gameSounds[MUNCH].loadFromFile("sounds/munch.wav");
	m_gameSounds[DEATH].loadFromFile("sounds/death.wav");
	m_gameSounds[LVL_UP].loadFromFile("sounds/lvl_up.wav");
	m_gameSounds[GAME_IS_OVER].loadFromFile("sounds/game_over.wav");
	m_gameSounds[EXPLO_SOUND].loadFromFile("sounds/bomb_sound.wav");
	m_gameSounds[SURPRISE_SOUND].loadFromFile("sounds/surprise.wav");
	m_gameSounds[POLICE_SOUND].loadFromFile("sounds/police_sound.wav");
	m_gameSounds[BIRD_SOUND].loadFromFile("sounds/bird_sound.wav");
	
	

	//FIGHT
	m_gameSounds[BOTTLE_S].loadFromFile("sounds/bottle_music.ogg");

	//add sound of goal


	//screens
	m_pScreeen[Menu_s].loadFromFile("screens/menu.jpg");
	m_pScreeen[INTRO].loadFromFile("screens/instruction.jpg");
	m_pScreeen[CHOOSE_CHARACTER].loadFromFile("screens/choose_player.jpg");
	m_pScreeen[HIGH_SCORE].loadFromFile("screens/high_score.jpg");
	m_pScreeen[ENTER_SCORE].loadFromFile("screens/enter_score.jpg");

	m_pScreeen[Coli_Dea].loadFromFile("screens/donde_pablo.jpg");
	m_pScreeen[Coli_pol].loadFromFile("screens/Plato_o_plomo500.jpg");
	m_pScreeen[GO_Jail].loadFromFile("screens/game_over_jail.jpg");
	m_pScreeen[GO_SHOT].loadFromFile("screens/game_over_shot.jpg");
	m_pScreeen[GO_WON].loadFromFile("screens/game_over_won.jpg");
	m_pScreeen[GO_DEAD].loadFromFile("screens/game_over_dead.jpg");


	m_pScreeen[lev1].loadFromFile("screens/back6.jpg");
	m_pScreeen[lev2].loadFromFile("screens/back.png");
	m_pScreeen[lev3].loadFromFile("screens/sky2.png"); 
	m_pScreeen[lev4].loadFromFile("screens/sea.jpg"); 

	m_pScreeen[SMOKING_A].loadFromFile("screens/smoking1.jpg");


	m_pScreeen[Coli_ps].loadFromFile("screens/Coli_ps.jpg");
	m_pScreeen[PAB_SHOOT].loadFromFile("screens/pablo_shoot.jpg");

	m_pScreeen[CaveS].loadFromFile("screens/cave_inside.jpg");
	m_pScreeen[PITCH_A].loadFromFile("screens/football_pitch.jpg");
	m_pScreeen[GOAL_A].loadFromFile("screens/screen_goal.jpg");

	// G.O SCREENS, MENU , CHOSSING, COLIISIONS, SKY, WATER

	//fonts
	m_lifeCount.loadFromFile("images/weed.png");
	m_font[GAME_FONT].loadFromFile("fonts/gameFont.otf");
	m_font[GET_READY_FONT].loadFromFile("fonts/getReadyFont.otf");

	//button

	m_pButton[NEW_GAME_b].loadFromFile("button/new_game.png");
	m_pButton[MENU_b].loadFromFile("button/menu.png");
	m_pButton[SOUND_b].loadFromFile("button/sound.png");
	m_pButton[INTRO_b].loadFromFile("button/intro.png");
	m_pButton[EXIT_b].loadFromFile("button/exit.png");
	m_pButton[HS_b].loadFromFile("button/hs.png");
	m_pButton[PLAY_b].loadFromFile("button/play.png");
	m_pButton[ENTER_SCORE_b].loadFromFile("button/enter.png");
	m_pButton[OK_b].loadFromFile("button/ok1.png");
	m_pButton[PLAY_b].loadFromFile("button/play.png");
	




}


FileManager & FileManager::getInstance()
{
	static FileManager instance;
	return instance;
}

const std::vector<high_score>& FileManager::loadHighScore()
{
	string file = "levels/highScore.txt";
	ifstream input_score;
	input_score.open(file);

	if (!input_score.is_open()){
		std::cerr << "could not open file\n";
		exit(EXIT_FAILURE);
	}
	m_listScore.clear();
	while (!input_score.eof())
	{
		m_listScore.push_back(high_score());
		input_score >> m_listScore.back().name;
		input_score >> m_listScore.back().score;
	}
	input_score.close();
	return m_listScore;
}

void FileManager::updateScore(string name, int score)
{
	auto highScore = loadHighScore();

	highScore.push_back(high_score{ score, name });
	std::sort(highScore.begin(), highScore.end(), [&](high_score i, high_score j) {
		return (i.score>j.score);
	});

	string file = "levels/highScore.txt";
	std::ofstream output;
	output.open(file);
	output.clear();

	for (int i = 0; i < 5 && i < highScore.size(); i++) {
		output << highScore[i].name << "\n" << highScore[i].score;
		if (i < 4 && i < highScore.size() - 1)
			output << "\n";
	}
	output.close();
}

sf::Texture * FileManager::getIconTexture(size_t shape)
{
	return &m_pTexture[shape];
}

sf::Texture * FileManager::getPlayerTexture(size_t shape)
{
	return &m_playerTexture[shape];
}

sf::Texture * FileManager::getPlayer2Texture(size_t shape)
{
	return &m_player2Texture[shape];
}

sf::Texture * FileManager::getPoliceManTexture(size_t shape)
{
	return &m_pcmTexture[shape];

}

sf::Texture * FileManager::getBirdTexture(size_t shape)
{
	return &m_birdTexture[shape];

}

sf::Texture * FileManager::getWolfTexture(size_t shape)
{
	return &m_wolfTexture[shape];
}

sf::Texture * FileManager::getLionTexture(size_t shape)
{
	return &m_lionTexture[shape];
}

sf::Texture * FileManager::getButtonTexture(size_t shape)
{
	return &m_pButton[shape];

}



sf::SoundBuffer * FileManager::getGameSound(size_t type)
{
	return &m_gameSounds[type];
}

sf::Texture * FileManager::getScreen(size_t screen)
{
	return &m_pScreeen[screen];
}

sf::Font * FileManager::getFont(size_t type)
{
	return &m_font[type];
}

sf::Texture * FileManager::getLifeTexture()
{
	return &m_lifeCount;
}

FileManager::~FileManager()
{
}
