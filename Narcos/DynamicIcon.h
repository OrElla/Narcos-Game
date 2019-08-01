#pragma once
#include "Tile.h"

class Bullet;
enum Direction_t { RIGHT, DOWN, LEFT, UP, JUMP, NONE};

const int DIFF_SIZE = 5;
const float SWITCH_FRAME = 15;
const float REGULAR_SPEED = 120;


struct Data {
	float jumpF = 800.f;
	float gravityAcceleration = 9.8f;
};

struct Physical {
	float mass = 0.f;
	float speedValue = 0.f;
	float speedAngel = 0.f;
	float accelerationValue = 0.f;
	float accelerationAngel = 0.f;
};

class DynamicIcon : public Tile, public Physical
{
public:
	DynamicIcon();
	~DynamicIcon();

	virtual void draw(sf::RenderWindow &window, float passedTime);
	virtual void move(sf::Clock& clock, sf::Vector2f boardSize){}
	void rotatePlayer(int rotate);
	void decLife();
	void collideGround(const Ground1 & ground);
	int getLife() const;
	bool dynamicVsBullet(DynamicIcon* bullet) { return false; }
	Direction_t getDirection();
	//sf::Vector2f getNextDirection(Direction_t direction);
	sf::Vector2f getStartingPosition();
	sf::Vector2f getPosition();
	void setStartingPosition(sf::Vector2f pos);
	void setSpeedValue(float value) { m_speedValue = value; }
	void setMass(int value) { m_mass = (float)value; }
	int getMass() { return m_mass; }
	float get_current_ground_y() { return m_current_ground_y; }
	void set_current_ground_y(float value) { m_current_ground_y = value; }
	void setAccelerationValue(float value) { accelerationValue = value; }
	sf::Vector2f getNextDirection(Direction_t direction);
	virtual void SetPosition(sf::Vector2f new_pos) = 0;

protected:
	sf::Vector2f m_startingPosition;
	bool isCentered(sf::Vector2f pos, sf::Vector2f center);
	bool outOfBoard(sf::Vector2f size);
	sf::Vector2f m_prevPos;
	sf::Vector2f getCenter(sf::Vector2f pos);
	sf::Vector2f m_pos;
	Direction_t m_direction;
	float m_frameCounter = 0;
	float m_distance = 0;
	float m_mass;
	float m_speedValue;
	float m_gravityAcceleration;
	float m_current_ground_y;
	int m_sourceX = 0;
	int m_life = 2;
};