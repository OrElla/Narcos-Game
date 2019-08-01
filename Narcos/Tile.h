#pragma once
#include <SFML\Audio.hpp>
#include "SFML\Graphics.hpp"
#include <iostream>
#include "FileManager.h"
#include "Exceptions.h"

class Pablo;
class Ground1;
class Level;
class Cave;
class Coin;
class Money;
class MoneyBag;
class Beer;
class Coc;
class Bullet;
class PoliceMan;
class FootBall;
class Energy;

const int WINDOW_HEIGHT = 600;
const int WINDOW_LENGTH = 800;
const int NUM_OF_SCORES = 5;
const int P_SIZE = 32;
const int FULL_COINS = 10;
const int LOGO_BACK = 2;
const int NUM_OF_BUTTONS = 5;
const int MAX_OF_BEER = 5;
const int TOP_5 = 5;


enum Menu_ID
{
	//MENU_BUTTON,
	CHOOSING_BUTTON,
	INTRO__BUTTON,
	HS_BUTTON,
	EXIT_BUTTON,
	SOUND_BUTTON
};
enum Intro_ID
{
	CHOOSING_Intro,
	SOUND_Intro,
	//MENU_Intro,
	EXIT_Intro
};

enum Choose_ID {PLAY_PABLO, PLAY_GACHA, EXIT_CHOOSE};
enum HighSC_ID {NEW_GAME_hs, SOUND_hs, EXIT_hs};
enum GO_WON_ID {NEW_GAME_WON, SOUND_WON, EXIT_WON};
enum gameSound_t { PLATO_O_PLOMO, SMOKING, SNIFFING,
	Menu_Sound,COINS, MONEY_s , MONEY_BAG_s , BOTTLE_S,
	KNIFE_SOUND , EATING_SOUND, MUNCH, DEATH,LVL_UP, GAME_IS_OVER,
	BULLETS_SOUND, EVIL_SOUND, HIJO_DE_PUTA, EXPLO_SOUND,
	SURPRISE_SOUND , BIRD_SOUND, POLICE_SOUND
};

enum Enter_ID {OK_enter , INPUT_enter};

enum Button_b { NEW_GAME_b, EXIT_b , HS_b, ENTER_SCORE_b,
				OK_b ,SOUND_b, PLAY_b, INTRO_b, MENU_b};

enum Object_t { PABLO, PP,GACHA,POLICEMAN,CAVE,DEA,ANIMAL,
	GROUND,TNt,BULLET,COC,ENERGY,GUN, KNIFE, POLICE_STATION,
	WEED,FOOD, COIN, MONEY, MONEY_BAG, BEER,
	SPECIAL_BEER, SOCCER_FRAME, FOOTBALL, GOAL_T,
	BLOOD , EXPLOSION
}; //CHANGE FOOD AND FLAG

enum Screen_a { lev1, lev2, lev3,lev4 , Snif , CaveS, Coli_pol,
	Coli_Dea,Coli_ps , Menu_s, GO_Jail,GO_DEAD,GO_SHOT, GO_WON,
	CHOOSE_CHARACTER,INTRO, SMOKING_A, PITCH_A, GOAL_A, PAB_SHOOT,
	HIGH_SCORE,ENTER_SCORE
};

enum Screen_m { MENU_m, MAP_TO_GAME_m, HS_m, ENTER_HS_m, GAME_OVER_m, INTRO_m };
enum ENTER_HS_h { MENU_h, INPUT_h, OK_h, SOUND_Gh };
enum GAME_OVER_f { MENU_f, PLAY_f, HS_f, SOUND_f };
enum Fonts_t { GAME_FONT, GET_READY_FONT };

enum Pablo_p
{
	P1, P2, P3, P4, P5, P6, P7, P8, P9, P10,
	P11, P12, P13, P14, P15, P16, P17, P18, P19,
	P20, P21 ,P22, P23, P24, P25, P26
};

enum Gacha_g {
	G1, G2, G3, G4, G5, G6, G7, G8
};

enum PoliceMan_po {
	PO1, PO2, PO3, PO4, PO5, PO6, PO7, PO8
};

enum Bird_b {
	Bird1, Bird2, Bird3, Bird4, Bird5, Bird6
};

enum Lion_l {
	LION1, LION2, LION3, LION4, LION5, LION6
};
enum Wolf_w {
	Wolf1, Wolf2, Wolf3, Wolf4, Wolf5, Wolf6
};
class Tile
{
public:
	Tile() {};

	sf::Sprite getSprite();
	bool getExist();
	void setExist(bool state);
	sf::Vector2f getPOS();
	virtual void f() {}

	~Tile() {};


protected:
	bool m_exist = true;
	Object_t m_type;
	sf::Sprite m_sprite;
	sf::Vector2f position;
};

