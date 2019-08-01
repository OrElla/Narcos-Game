#pragma once
#include "Tile.h"
#include "Map.h"
#include "Level.h"
#include "Bullet.h"
#include "PlayerState.h"
#include "GAME_OVER_WON.h"
#include "GameOverDead.h"
#include "GameOverJail.h"
#include "CollisionHandling.h"


const int NUM_OF_LEVEL = 5;
const int WINDOW_SIZE = 1000;

const string LIFE_CHEAT = "11854";
const string SCORE_CHEAT = "1215148131918";
const string AIR_CHEAT = "34121413";


class Controller
{
public:
	Controller();
	void run(sf::RenderWindow & window); //CHANGE TO BOOL

	~Controller();

private:
	void checkCollision();
	vector<shared_ptr<DynamicIcon>>m_Dynamics;
	int m_levelNumber = 1;
	Level m_level;


	bool levelFinished(sf::RenderWindow & window);
	void resetGame(sf::RenderWindow & window, bool & isMoving);
	void drawNextLevel(sf::RenderWindow & window);
	void drawGetReady(sf::RenderWindow & window);

	void levelUp(bool & isMoving, sf::RenderWindow & window);
	bool isOver(sf::RenderWindow & window);

	sf::Texture m_texture; //change
	sf::Sprite m_backGroundScreen[10];
	sf::Text m_getReady;

	void draw(sf::RenderWindow & window, float passedTime);
	void setPabloDirection(sf::Keyboard::Key direction);
	void drawDynamic(sf::RenderWindow & window, float passedTime);
	void moveDynamic(sf::RenderWindow & window, sf::Clock & clock);
	void setDirection(sf::Event newEvent, sf::Clock & clock);
	void doBomb();
	void drawBomb(sf::RenderWindow & window);

	void checkEvent(sf::RenderWindow & window, sf::Clock & clock, sf::Event Event);
	void setDynamics(sf::RenderWindow & window);
	bool OutOfBoard(sf::Vector2f place,
		const vector <vector<std::unique_ptr<StaticIcon>>> & board);
	void checkEnemy(sf::RenderWindow & window);
	void checkPlayer();


	std::shared_ptr<Pablo>m_pab;
	//vector <std::unique_ptr<PoliceMan>> m_policeMan;
	bool isJump = false;
	bool is_air = false;

	Data data;
	bool isFire = false;
	bool checkForHs(int highScores[], int score, int & i);
	void Cheats(sf::Keyboard::Key  key);

	sf::Sound m_sound[NUM_OF_SOUNDS];
	sf::Sprite m_screens[NUM_OF_SCREENS];
	vector<std::shared_ptr<DynamicIcon>>m_Bullet;
	vector<std::shared_ptr<StaticIcon>>m_Bomb;

	PlayerState m_statesBar;

	GAME_OVER_WON go_won;
	GameOverDead go_dead;
	GameOverJail go_jail;
	bool m_pcm_first = false;
	int pcm_counter = 0;
	int gap;
	sf::Font m_font;
	bool isMoving = false;
	string m_lifeCheat;
	string m_pointsCheat;
	string m_airCheat;
	void mute(sf::Music & GameMusic);
	sf::Music GameMusic;
	sf::Music GameWon;

	bool m_mute = false;
	bool gotShot = false;
	int counter1 = m_Bomb.size();

};

