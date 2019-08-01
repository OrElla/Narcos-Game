#include "Pablo.h"
#include <iostream>
#include "Level.h"
#include <cmath>
#include "Bird.h"

// maybe #inlcude "Animal.h" 
// maybe #Include "PoliceMan.h"

//--------------------------------------------------------
//CREATES THE PLAYER
bool Pablo::m_register = FactoryDynamic::registerIt('@',
	[]()->std::shared_ptr<DynamicIcon> {return std::make_unique<Pablo>(); });
//--------------------------------------------------------
//CONSTUCTOR OF THE MAIN PLAYER
Pablo::Pablo() : 
	m_state (std::make_unique<StandingState>())
{
	m_sprite.setTexture(*(FileManager::getInstance().getPlayerTexture(P1)));
	m_sprite.setOrigin(getCenter(m_sprite.getPosition()));
	SetPosition(m_sprite.getOrigin());
	
	m_screen[Coli_Dea].setTexture(*(FileManager::getInstance().getScreen(Coli_Dea)));
	m_screen[Coli_ps].setTexture(*(FileManager::getInstance().getScreen(Coli_ps)));
	m_screen[PITCH_A].setTexture(*(FileManager::getInstance().getScreen(PITCH_A)));
	m_images[GOAL_T].setTexture(*(FileManager::getInstance().getIconTexture(GOAL_T)));
	m_images[FOOTBALL].setTexture(*(FileManager::getInstance().getIconTexture(FOOTBALL)));
	m_sounds[BULLETS_SOUND].setBuffer(*(FileManager::getInstance().getGameSound(BULLETS_SOUND)));
	m_sounds[BULLETS_SOUND].setVolume(70);

	m_life = 3;
	//move to menu
	//m_sounds[Menu_Sound].setBuffer(*(FileManager::getInstance().getGameSound(Menu_Sound)));
}

Pablo::~Pablo()
{
}

void Pablo::jump()
{
	m_velocity.y = -m_jumpspeed;
}

void Pablo::setcollidepoliceman(bool state)
{
	collidepoliceman = state;
}

bool Pablo::getcollidepoliceman()
{
	return collidepoliceman;
}
//--------------------------------------------------------
//MANAGE MOVING
void Pablo::handleInput(INPUT input)
{
	unique_ptr<State> state_ = m_state->handleInput(input);
	if (state_)
	{
		m_state = std::move(state_);
		m_state->enter(*this);
	}
}
 
//--------------------------------------------------------
//SET NEW POSITION OF THE PLAYER
void Pablo::SetPosition(sf::Vector2f new_pos)
{
	m_sprite.setPosition(getCenter(new_pos));
}
//--------------------------------------------------------
//SET NEW DIRECTION OF THE PLAYER
void Pablo::setDirection(sf::Keyboard::Key direction)
{
	switch (direction)
	{
	case sf::Keyboard::Left:
		m_newDirection = LEFT;
		break;
	case sf::Keyboard::Right:
		m_newDirection = RIGHT;
		break;
	case sf::Keyboard::Up: //jump
		//do jump
		m_newDirection = UP;
		break;
	case sf::Keyboard::Down:
		m_newDirection = DOWN;
		break;
	case sf::Keyboard::Space:
		m_newDirection = JUMP;
	}
}
//--------------------------------------------------------
//MANAGE COLLISIONS WITH DYNAMIC OBJECTS
bool Pablo::pabloVsDynamic(DynamicIcon * dynamicIcon,
	vector<std::shared_ptr<DynamicIcon>>&m_bullet)
{
	PoliceMan * policeMan = dynamic_cast<PoliceMan*>(dynamicIcon);
	if (policeMan)
	{
		if (sqrt(pow(m_sprite.getPosition().x - policeMan->getSprite().getPosition().x, 2) +
			pow(m_sprite.getPosition().y - policeMan->getSprite().getPosition().y, 2)) >=
			150)
		{
			policeMan->setcanshoot(true);
			collidepoliceman = true;
			return false;
		}
		if (policeMan->getcanshoot())
		{
			sf::Vector2f bulletPos;
			policeMan->goesleft() ?
				bulletPos.x = policeMan->getSprite().getPosition().x + 100 :
				bulletPos.x = policeMan->getSprite().getPosition().x + 100;
			bulletPos.y = policeMan->getSprite().getPosition().y + 0.5*(policeMan->getSprite().getGlobalBounds().height);
			m_bullet.emplace_back(m_bulletsPtr->CreateBullets('~', bulletPos, true));
			policeMan->setcanshoot(false);
		}
		return true;
	}
	else
	{
		Bird * animal = dynamic_cast<Bird*>(dynamicIcon);
		if(animal)
		if (m_sprite.getGlobalBounds().intersects(animal->getSprite().getGlobalBounds()))
			return true;
	}
	return false;
}

//--------------------------------------------------------
//DRAWING THE PLAYER
void Pablo::draw(sf::RenderWindow & window, float passedTime)
{
	if (m_collectedCounter == 0 || m_isEaten)
	{
		//m_direction = RIGHT;//

		//m_direction = LEFT;
		m_speed = REGULAR_SPEED;
	}
	m_frameCounter += passedTime * m_speed;
	if (m_frameCounter > SWITCH_FRAME)
	{
		m_frameCounter = 0;
		m_sourceX++;
	}

	window.draw(m_sprite);

}
//--------------------------------------------------------
// SAVE THE LAST DIRECTION
Direction_t Pablo::getDirection()
{
	return m_direction;
}
//--------------------------------------------------------
// GET LIFE OF THE PLAYER
/*
int Pablo::getLife()
{
	return m_life;
}
*/
//--------------------------------------------------------
// CHECK IF THE PLAYER HAS LIFE
bool Pablo::getPabloState()
{
	return m_isEaten;
}
//--------------------------------------------------------
// SET THE PLAYER STATE
void Pablo::setPabloState()
{
	m_isEaten = false;
}
//--------------------------------------------------------
// SET THE COLLECTED COUNTER
void Pablo::setCollectedCounter(int x)
{
	m_collectedCounter += x;
}
//--------------------------------------------------------
// GET THE COLLECTED COUNTER
int Pablo::getCollected() const
{
	return m_collectedCounter;
}
//--------------------------------------------------------
// GET THE SCORE
int Pablo::getScore() const
{
	return m_score;
}
//--------------------------------------------------------
// SET THE LIFE
void Pablo::setLife(int x)
{
	if (m_life < 3)
		m_life += x;
}
//--------------------------------------------------------
// SET THE SCORE
void Pablo::setScore(int x)
{
	m_score += x;
}

//--------------------------------------------------------
// IF THE PLAYER JUMPING
void Pablo::jump(float deltaTime)
{
	Data data;
	m_speedValue -= data.gravityAcceleration * deltaTime;
	m_sprite.move(0, m_speedValue);
	//m.characterColision();
}

//--------------------------------------------------------
// RETURN THE BEER COUNTER
int Pablo::getBeer() const
{
	return m_counters._Beer;
}

//--------------------------------------------------------
// CHEECKS IF THE BEER COLLECTED IS MAXIMUM
bool Pablo::maxBeer()
{
	return totalBeer >= MAX_OF_BEER;
}

//--------------------------------------------------------
// DEFINES THE TEXTURE ACOORDING ITEMS AND DIRECTION
void Pablo::StandDirection(Direction_t pressed)
{
	int frame = checkCharacterDirection(pressed);
	switch (frame)
	{
	case 1:
		m_sprite.setTexture(*(FileManager::getInstance().getPlayerTexture(P1)));
		break;
	case 2:
		m_sprite.setTexture(*(FileManager::getInstance().getPlayerTexture(P2)));
		break;
	case 3:
		m_sprite.setTexture(*(FileManager::getInstance().getPlayerTexture(P3)));
		break;
	case 4:
		m_sprite.setTexture(*(FileManager::getInstance().getPlayerTexture(P4)));
		break;
	case 5:
		m_sprite.setTexture(*(FileManager::getInstance().getPlayerTexture(P5)));
		break;
	case 6:
		m_sprite.setTexture(*(FileManager::getInstance().getPlayerTexture(P6)));
		break;
	case 7:
		m_sprite.setTexture(*(FileManager::getInstance().getPlayerTexture(P7)));
		break;
	case 8:
		m_sprite.setTexture(*(FileManager::getInstance().getPlayerTexture(P8)));
		break;
	case 9:
		m_sprite.setTexture(*(FileManager::getInstance().getPlayerTexture(P9)));
		break;
	case 10:
		m_sprite.setTexture(*(FileManager::getInstance().getPlayerTexture(P10)));
		break;
	case 11:
		m_sprite.setTexture(*(FileManager::getInstance().getPlayerTexture(P11)));
		break;
	case 12:
		m_sprite.setTexture(*(FileManager::getInstance().getPlayerTexture(P12)));
		break;
	case 13:
		m_sprite.setTexture(*(FileManager::getInstance().getPlayerTexture(P13)));
		break;
	case 14:
		m_sprite.setTexture(*(FileManager::getInstance().getPlayerTexture(P14)));
		break;
	case 15:
		m_sprite.setTexture(*(FileManager::getInstance().getPlayerTexture(P15)));
		break;
	case 16:
		m_sprite.setTexture(*(FileManager::getInstance().getPlayerTexture(P16)));
		break;
	case 17:
		m_sprite.setTexture(*(FileManager::getInstance().getPlayerTexture(P17)));
		break;
	case 18:
		m_sprite.setTexture(*(FileManager::getInstance().getPlayerTexture(P18)));
		break;
	case 19:
		m_sprite.setTexture(*(FileManager::getInstance().getPlayerTexture(P19)));
		break;
	case 20:
		m_sprite.setTexture(*(FileManager::getInstance().getPlayerTexture(P20)));
		break;
	case 23:
		m_sprite.setTexture(*(FileManager::getInstance().getPlayerTexture(P23)));
		break;
	case 24:
		m_sprite.setTexture(*(FileManager::getInstance().getPlayerTexture(P24)));
		break;
	case 25:
		m_sprite.setTexture(*(FileManager::getInstance().getPlayerTexture(P25)));
		break;
	case 26:
		m_sprite.setTexture(*(FileManager::getInstance().getPlayerTexture(P26)));
		break;
	}

	m_newDirection = pressed;
}
//--------------------------------------------------------
// IF THE PLAYER WANTS TO SHOOT
std::shared_ptr<DynamicIcon> Pablo::shooting()
{	
	sf::Vector2f bulletPos = m_sprite.getPosition();
	bulletPos.x += (float)49;
	bulletPos.y += (float)40-0.5f;

	if (canShoot()){
		m_sounds[BULLETS_SOUND].play();
		m_sprite.move(-5*distance, 0);
		m_counters._Bullet--;
		//m_images[BLOOD].setPosition(m_sprite.getPosition());
		return m_bulletsPtr->CreateBullets('~', bulletPos, true);
	}
	return {};
}
//--------------------------------------------------------
// SET THE BEER COUNTER
void Pablo::setBeerCounter(int x)
{
	m_counters._Beer += x;
}
//--------------------------------------------------------
// IF THE PLAYER CAN SHOOT
bool Pablo::canShoot()
{
	return m_counters._Bullet > 0;
}
//--------------------------------------------------------
// IF THE PLAYER CAN USE TNT
bool Pablo::getBomb()
{
	return m_counters._TNT > 0; 
}
void Pablo::setcollideground(bool state)
{
	collideground = state;
}
//--------------------------------------------------------
// IF THE PLAYER is on air Mode
bool Pablo::airMode()
{
	return m_moving.m_air;
}

void Pablo::setvolecity()
{
	m_velocity.x = 0;
}

/*
//make unique tnt
//draw tnt
//draw 3 2 1
//draw bomb
*/

//--------------------------------------------------------
// SET THE BEERS COUNTER
void Pablo::setBeer(int num)
{
	m_counters._Beer = num;
}

//--------------------------------------------------------
// DEFINES AIRPLANE MODE
void Pablo::airPlane()
{
	//sf::tex prev_sprite = m_sprite.getSprite();
	sf::Clock c;
	float air_time = 4;
	c.restart();
	if (c.getElapsedTime().asSeconds() <= air_time) {
		m_moving.m_air = true;
		m_sprite.setTexture(*(FileManager::getInstance().getPlayerTexture(P23)));
	}
	m_moving.m_air = false;

	//m_sprite.setTexture(prev_sprite);
	m_sprite.setTexture(*(FileManager::getInstance().getPlayerTexture(P3)));
}

//--------------------------------------------------------
// SET THE ENERGY COUNTER
void Pablo::setEnergy(int num)
{
	m_counters._Energy = num;
}
void Pablo::setSprite(int levelNum)
{
	switch (levelNum)
	{
	case 3:
	{
	m_sprite.setTexture(*(FileManager::getInstance().getPlayerTexture(P23)));
	m_moving.m_air = right;

	m_sprite.setScale(sf::Vector2f(3*((float)P_SIZE / m_sprite.getGlobalBounds().height),
		3 * ((float)P_SIZE / m_sprite.getGlobalBounds().height)));
	break;
	}
	case 4:
	{
		m_sprite.setTexture(*(FileManager::getInstance().getPlayerTexture(P25)));
		m_moving.m_air = false;
		m_moving.m_sea = right;
		m_sprite.setScale(sf::Vector2f(3 * ((float)P_SIZE / m_sprite.getGlobalBounds().height),
			3 * ((float)P_SIZE / m_sprite.getGlobalBounds().height)));
		break;
	}
	default:
		break;
	}
}
//--------------------------------------------------------
// CHECKS THE COLLECTED ITMES AND DIRECTION
int Pablo::checkCharacterDirection(Direction_t pressed)
{
	switch (pressed)
	{
	case LEFT:
	{
		m_moving.m_right = true;
		m_moving.m_left = false;
		m_moving.m_jump = false;
		m_moving.m_stand = false;
		break;
	}
	case RIGHT:
	{
		m_moving.m_right = false;
		m_moving.m_left = true;
		m_moving.m_jump = false;
		m_moving.m_stand = false;
		break;
	}
	case UP:
	{
		m_moving.m_jump = true;
		m_moving.m_stand = false;
		break;
	}
	/*
	case JUMP:
	{
	
	}*/

	case NONE:
	{
		m_moving.m_stand = true;
		break;
	}		
	}

	if (m_moving.m_air){
		if (m_moving.m_right)
			return 24;
		else
			return 23;
	}


	if (m_moving.m_sea) {
		if (m_moving.m_right)
			return 25;
		else
			return 26;
	}

	if (m_moving.m_stand)
	{
		if (m_moving.m_right)
		{
			if (m_counters._Bullet > 0)
				return 8;
			else if (m_counters._TNT > 0)
				return 14;
			else if (m_counters._Knife > 0)
				return 12;
			else
				return 2;
		}

		else if (m_moving.m_left)
		{
			if (m_counters._Bullet > 0)
				return 7;
			else if (m_counters._TNT > 0)
				return 13;
			else if (m_counters._Knife > 0)
				return 11;
			else
				return 1;
		}
	}


	if (m_moving.m_jump)
	{
		if (m_moving.m_right)
			return 6;
		else
			return 5;
	}


	if (m_moving.m_right)
	{
		if (m_counters._Bullet > 0)
			return 18;
		else if (m_counters._TNT > 0)
			return 16;
		else if (m_counters._Knife > 0)
			return 20;
		else
			return 4;
	}

	else if (m_moving.m_left) 
	{
		if (m_counters._Bullet > 0)
			return 17;
		else if (m_counters._TNT > 0)
			return 15;
		else if (m_counters._Knife > 0)
			return 19;
		else
			return 3;
	}
}
//--------------------------------------------------------
// SET THE counters struct
Counters & Pablo::SetCounters()
{
	return m_counters;
}
//--------------------------------------------------------
// SET THE MOVING struct
Moving & Pablo::SetMoving()
{
	return m_moving;
}
//--------------------------------------------------------
// check IF Speacial Tile
void Pablo::checkSpeacialTile(float passedTime)
{
	//
}
//--------------------------------------------------------
// MOVING THE PLAYER
void Pablo::move(sf::Clock& clock, sf::Vector2f boardSize)
{
	m_prevPos = m_sprite.getPosition();
	m_direction = m_newDirection;
	switch (m_direction)
	{
	case RIGHT:
	{
		StandDirection(RIGHT);
		m_velocity.x = m_movingspeed;
		break;
	}
	case LEFT:
	{
		StandDirection(LEFT);
		m_velocity.x = -m_movingspeed;
		break;
	}
	case NONE:
	{
	StandDirection(NONE);
	m_velocity.x = 0;
	break;
	}
	}

	if ((m_sprite.getPosition().y + m_sprite.getGlobalBounds().height<m_groundHight || m_velocity.y < 0) && !collideground)
		m_velocity.y += gravity;
	else
		m_velocity.y = 0;

	m_sprite.move(m_velocity);
	if (outOfBoard(boardSize))
		m_sprite.setPosition(m_prevPos);

	/*
	switch (m_direction)
	{
	case UP:
	{
		StandDirection(UP);
		m_sprite.move(0, -distance);
		break;
	}
	case DOWN:
		StandDirection(DOWN);
		m_sprite.move(0, distance);
		break;
	case RIGHT:
	{
		StandDirection(RIGHT);
		m_sprite.move(distance, 0);
		break;
	}
	case LEFT:
	{
		StandDirection(LEFT);
		m_sprite.move(-distance, 0);
		break;
	}
	case JUMP:
	{
		StandDirection(JUMP);
		jump(0.015);
		break;
	}
	case NONE:
		break;
	}
*/
}