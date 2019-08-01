#pragma once
#include "Player.h"
#include "FactoryDynamic.h"

const float gravity = 1.0f;
struct Counters
{
	int _Coin = 0;
	int _Money = 0;
	int _MoneyBag = 0;
	int _Weed = 0;
	int _Coc = 0;
	int _Knife = 0;
	int _Bullet = 0;
	int _Food = 0;
	int _Beer = 0;
	int _TNT = 0;
	int _Energy = 3;
};

struct Moving
{
	bool m_right = false;
	bool m_left = false;
	bool m_up = false;
	bool m_knife = false;
	bool m_jump = false;
	bool m_stand = false;
	bool m_air = false;
	bool m_sea = false;
	bool m_smoke = false;
};


class Policeman;
class Animal;

class Pablo : public Player
{
public:
	Pablo();
	~Pablo();
	void jump();
	void setcollidepoliceman(bool state);
	bool getcollidepoliceman();
	virtual void handleInput(INPUT input);
	void SetPosition(sf::Vector2f new_pos);
	void setDirection(sf::Keyboard::Key direction);
	bool pabloVsDynamic(DynamicIcon * dynamicIcon , 
		vector<std::shared_ptr<DynamicIcon>>&m_bulletsPtr);
	void draw(sf::RenderWindow &window, float passedTime);
	void move(sf::Clock& clock, sf::Vector2f boardSize);
	Direction_t getDirection();
	//int getLife();
	bool getPabloState();
	void setPabloState();
	void setCollectedCounter(int x);
	int getCollected() const;
	int getScore() const;
	void setLife(int x);
	void setScore(int x);
	void jump(float deltaTime); //fix
	int getBeer() const;
	bool maxBeer();
	void StandDirection(Direction_t release);
	void setBeer(int num);
	void airPlane();
	void setEnergy(int num);
	void setSprite(int levelNum);

	Counters & SetCounters();
	Moving & SetMoving();
	std::shared_ptr<DynamicIcon> shooting();

	void setBeerCounter(int x);
	bool canShoot();
	bool getBomb();
	void setcollideground(bool state);
//	void doBomb();
	bool airMode();
	void setvolecity();
private:
	bool collidepoliceman;
	sf::Vector2f m_velocity = sf::Vector2f(0, 0);
	bool collideground;
	int m_groundHight = 580;
	float m_movingspeed = 5.0f;
	float m_jumpspeed = 15.0f;
	Counters m_counters;
	Moving m_moving;
	int totalBeer = 0;
	static bool m_register;
	void checkSpeacialTile(float passedTime);
	int m_collectedCounter = 1;
	float m_speed = 5;
	Direction_t m_newDirection;
	int m_score = 0;
	//int m_life = 3;
	//int m_bullets = 2;
	bool m_isEaten;
	int m_numOfEnemies;
	//sf::Sound m_sounds[NUM_OF_SOUNDS - 2];
	float distance=5;
	std::unique_ptr<State> m_state;

	//sf::SoundBuffer m_sounds[NUM_OF_SOUNDS - 2];
	sf::Sound m_sounds[NUM_OF_SOUNDS];
	sf::Sprite m_screen[NUM_OF_SCREENS];
	sf::Sprite m_images[NUM_OF_IM];
	std::shared_ptr<FactoryDynamic>m_bulletsPtr;
	std::shared_ptr<FactoryDynamic>m_PCMPtr;

	int checkCharacterDirection(Direction_t pressed);
};




