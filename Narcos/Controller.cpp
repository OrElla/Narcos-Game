#include "Controller.h"
#include <cmath>

//-----------------------------------------------------------------------------
// cons. - defines images
Controller::Controller() :
	m_level(m_Dynamics, m_levelNumber)
{
	m_pab = std::dynamic_pointer_cast<Pablo>(m_Dynamics[0]);

	m_sound[LVL_UP].setBuffer(*(FileManager::getInstance().getGameSound(LVL_UP)));
	m_sound[GAME_IS_OVER].setBuffer(*(FileManager::getInstance().getGameSound(GAME_IS_OVER)));
	m_sound[EVIL_SOUND].setBuffer(*(FileManager::getInstance().getGameSound(EVIL_SOUND)));
	m_sound[HIJO_DE_PUTA].setBuffer(*(FileManager::getInstance().getGameSound(HIJO_DE_PUTA)));
	m_sound[EXPLO_SOUND].setBuffer(*(FileManager::getInstance().getGameSound(EXPLO_SOUND)));
	m_sound[EXPLO_SOUND].setVolume(75);
	m_sound[SURPRISE_SOUND].setBuffer(*(FileManager::getInstance().getGameSound(SURPRISE_SOUND)));
	m_sound[SURPRISE_SOUND].setVolume(75);
	m_screens[EXPLOSION].setTexture(*(FileManager::getInstance().getIconTexture(EXPLOSION)));
	m_screens[BLOOD].setTexture(*(FileManager::getInstance().getIconTexture(BLOOD)));
	m_sound[POLICE_SOUND].setBuffer(*(FileManager::getInstance().getGameSound(POLICE_SOUND)));
	m_sound[POLICE_SOUND].setVolume(75);
	m_sound[BIRD_SOUND].setBuffer(*(FileManager::getInstance().getGameSound(BIRD_SOUND)));
	m_sound[BIRD_SOUND].setVolume(75);


	GameMusic.openFromFile("sounds/play_sound.ogg");
	GameMusic.setVolume(75);
	GameWon.openFromFile("sounds/diablo_song.ogg");

	if (!m_texture.loadFromFile("screens/back6.jpg"))
		std::cout << "COULD NOT LOAD SCREEN!";

	for (size_t i = 0; i < 5; i++)
	{
		m_backGroundScreen[i].setTexture(*(FileManager::getInstance().getScreen(lev1)));
		m_backGroundScreen[i].setPosition(i*1024,0);
	}
	m_font = *(FileManager::getInstance().getFont(GET_READY_FONT));
	m_getReady.setFont(m_font);
}
//-----------------------------------------------------------------------------
// runnig the game
void Controller::run(sf::RenderWindow & window)
{
	//window.setKeyRepeatEnabled(false);
	window.setVerticalSyncEnabled(true);
	window.setJoystickThreshold(600);

	float passedTime=0;

	float moveSpeed = 1000.00f;
	sf::Vector2f position(window.getSize().x/2, window.getSize().y/2);

	for (size_t i = 0; i < 5; i++)
		m_backGroundScreen[i].setScale(1.0f,
		((float)window.getSize().y / m_texture.getSize().y));

	static sf::Clock clock;

	//m_pab->setMass(80);
	sf::View view, view_map;
	view.reset(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));
	view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));

	view_map.reset(sf::FloatRect(0, 0, window.getSize().x*2, window.getSize().y*2));
	view_map.setViewport(sf::FloatRect(0.5f, 0, 0.25f, 0.25f));

	while (window.isOpen())
	{
		GameMusic.play();
		window.display();
		drawGetReady(window);

		while (!isOver(window))
		{
		if (levelFinished(window))
		{
				m_levelNumber++;
				if (m_levelNumber <= NUM_OF_LEVEL)					
						levelUp(isMoving, window);
		}		

		for (size_t i = 0; i < 5; i++)
			window.draw(m_backGroundScreen[i]);//menu

			sf::Event Event;
			while (window.pollEvent(Event))
 					checkEvent(window, clock, Event);

			moveDynamic(window, clock);

			//view moves according pablo's moves
			if (m_pab->getPosition().x + 10 > window.getSize().x / 2)
				position.x = m_pab->getPosition().x + 10;
			else
				position.x = window.getSize().x / 2;

			checkPlayer(); //check jumping
			checkEnemy(window);
			view.setCenter(position);
			view_map.setCenter(position);
			window.setView(view_map);
			//draw(window, passedTime);
			window.setView(view);

			draw(window, passedTime);
			window.display();
			window.clear();		
		}
		break;
	}
	resetGame(window, isMoving);
	//return checkForHs(highScores, m_pab.getScore(), i);
}
//-----------------------------------------------------------------------------
// checks if level Finished
bool Controller::levelFinished(sf::RenderWindow & window)
{
	if (m_pab->getBeer() >= 1)
	{ 
		m_pab->setBeer(0);
		return true;
	}
	return false;
}

//-----------------------------------------------------------------------------
// reset for new Game
void Controller::resetGame(sf::RenderWindow & window, bool & isMoving)
{
	m_pab->setEnergy(3);
	m_pab->setLife(3);

	m_level.setBoard().clear();
	m_levelNumber = 1;
	m_pab->setBeerCounter(-m_pab->getBeer());
	m_level.read_level(m_Dynamics, m_levelNumber);
	isMoving = false;
}

//-----------------------------------------------------------------------------
// draw Get Ready !
void Controller::drawGetReady(sf::RenderWindow & window)
{
	std::string getReady;
	float time = 0;
	float dale = 3.0f;
	sf::Clock clock;
	clock.restart();
	m_getReady.setColor(sf::Color::White);
	m_getReady.setCharacterSize(WINDOW_HEIGHT / 10);
	m_getReady.setOutlineColor(sf::Color::Blue);
	m_getReady.setOutlineThickness(3);

	for (int i = 0; i < 3;)
	{
		getReady = "GET READY!  " + std::to_string(3 - i);
		time += clock.getElapsedTime().asSeconds();
		draw(window, dale);

		m_getReady.setPosition((WINDOW_LENGTH / 2) - 140
			,(WINDOW_HEIGHT / 2) - 120);

		m_getReady.setString(getReady);
		window.draw(m_getReady);
		window.display();
		window.clear();
		if (time >= 45)
		{
			i++;
			time = 0;
			clock.restart();
		}
	}
}
//-----------------------------------------------------------------------------
// draw Next Level !
void Controller::drawNextLevel(sf::RenderWindow & window)
{
	std::string next;
	float time = 0;
	float dale = 3.0f;
	sf::Clock clock;
	clock.restart();
	m_getReady.setColor(sf::Color::White);
	m_getReady.setCharacterSize(WINDOW_HEIGHT / 10);
	m_getReady.setOutlineColor(sf::Color::Blue);
	m_getReady.setOutlineThickness(3);
	for (int i = 0; i < 3;)
	{
		next = "NEXT LEVEL!  " + std::to_string(3 - i);
		time += clock.getElapsedTime().asSeconds();
		draw(window, time);
		m_getReady.setPosition((window.getSize().x / 2) - 140
			, (window.getSize().y / 2) - 120);
		m_getReady.setString(next);
		window.draw(m_getReady);
		window.display();
		window.clear();

		if (time >= 45)
		{
			i++;
			time = 0;
			clock.restart();
		}
	}
}
//-----------------------------------------------------------------------------
// updates the board for next level
void Controller::levelUp(bool & isMoving, sf::RenderWindow & window)
{
	m_sound[LVL_UP].play();

	m_Dynamics.clear();
	m_level.clearAll();
	m_level.read_level(m_Dynamics, m_levelNumber);
	m_pab = std::dynamic_pointer_cast<Pablo>(m_Dynamics[0]);

	//isMoving = false;

	window.create(sf::VideoMode(800,
		600+50), " Dale sin miedo");

	
	for (size_t i = 0; i < 5; i++)
	{
		if (m_levelNumber == 2)
			m_backGroundScreen[i].setTexture(*(FileManager::getInstance().getScreen(lev2)));
		else if (m_levelNumber == 3) {
			m_backGroundScreen[i].setTexture(*(FileManager::getInstance().getScreen(lev3)));

			m_backGroundScreen[i].setScale(1.0f, ((float)window.getSize().y /
				(FileManager::getInstance().getScreen(lev1))->getSize().y));
			m_pab->setSprite(3);
			
		}
		else if (m_levelNumber == 4) {
			m_backGroundScreen[i].setTexture(*(FileManager::getInstance().getScreen(lev4)));
			m_pab->setSprite(4);
			
		}
		m_backGroundScreen[i].setPosition(i * 800, 0);

		if(m_levelNumber != 3)
		m_backGroundScreen[i].setScale(1.0f,
			((float)window.getSize().y / m_texture.getSize().y));
	
	}
	

	drawNextLevel(window);
}
//-----------------------------------------------------------------------------
// checks if the game is over - jail/dead/win
bool Controller::isOver(sf::RenderWindow & window)
{
	if (m_pab->getLife() <= 0){
		m_sound[GAME_IS_OVER].play();
		go_dead.execute(window);
	}

	else if (m_pab->maxBeer()) {
		m_sound[HIJO_DE_PUTA].play();
		GameWon.play();
		go_won.execute(window);
	}

	else if (m_pab->getCollected() < 0) {
		m_sound[EVIL_SOUND].play();
		go_jail.execute(window);
	}

	else
		return false;
}
//-----------------------------------------------------------------------------

Controller::~Controller()
{
}
//-----------------------------------------------------------------------------
// checks the objects'es collision
void Controller::checkCollision()
{
	m_pab->setcollideground(false);
	
	int index = -1;
	vector<shared_ptr<StaticIcon>> &staticArr = m_level.getStatics();
	for (int i = 0; i < m_Dynamics.size(); i++)
	{
		// Dynamic - Static
		for (int j = 0; j < staticArr.size(); j++)
		{
			if (m_Dynamics[i]->getSprite().getGlobalBounds().
				intersects(staticArr[j]->getSprite().getGlobalBounds()))
			{
				processCollision(*(m_Dynamics[i]), *(staticArr[j]));
				index = j;
			}
		}

		// Pablo - Dynamic
		if (i != 0 && m_pab->pabloVsDynamic(m_Dynamics[i].get(), m_Bullet))
		{
			processCollision(*(m_Dynamics[0]), *(m_Dynamics[i]));
			
		}

		// Dynamic - Bullet
		for (size_t j = 0; j < m_Bullet.size(); j++)
			if (m_Dynamics[i]->getSprite().getGlobalBounds().
				intersects(m_Bullet[j]->getSprite().getGlobalBounds()))
			{
				processCollision(*(m_Dynamics[i]), *(m_Bullet[j]));
				m_Bullet.erase(m_Bullet.begin() + j);
				m_screens[BLOOD].setScale(2.5, 2.5);
				m_screens[BLOOD].setPosition(m_Dynamics[i]->getPosition());

				//draw(window, 50);
				gotShot = true;
				if (m_Dynamics[i]->getLife() <= 0) {
					m_Dynamics.erase(m_Dynamics.begin() + i);
				
					gotShot = false;
				}
				else
				{
					m_sound[POLICE_SOUND].play();
					m_sound[BIRD_SOUND].play();
				}
			}

		// static - Bomb
		/*
		for (size_t j = 0; j < m_Bomb.size(); j++)
			if (staticArr[i]->getSprite().getGlobalBounds().
				intersects(m_Bomb[j]->getSprite().getGlobalBounds()))
			{
				processCollision(*(staticArr[i]), *(m_Bomb[j]));
				m_Bomb.erase(m_Bomb.begin() + j);
				index = j;
			}*/
	}

	//todo - bomb with pcs
	if(index != -1)
	m_level.deleteObj(index);
}

//-----------------------------------------------------------------------------
// draw the obejects
void Controller::draw(sf::RenderWindow & window, float passedTime)
{
	m_level.drawStatic(window);
	m_statesBar.draw(window, m_pab->getLife(), m_pab->getScore(), m_levelNumber, m_pab->getPosition(),
		m_pab->SetCounters()._TNT, m_pab->SetCounters()._Food, m_pab->SetCounters()._Bullet,
		m_pab->SetCounters()._Coc, m_pab->SetCounters()._Knife, m_pab->SetCounters()._Energy);

	drawDynamic(window, passedTime);
}
//-----------------------------------------------------------------------------
// set the player Direction
void Controller::setPabloDirection(sf::Keyboard::Key direction)
{
	m_pab->setDirection(direction);
}
//-----------------------------------------------------------------------------
// draw Dynamic objects
void Controller::drawDynamic(sf::RenderWindow & window, float passedTime)
{
	for (int i = 0; i < m_Dynamics.size(); i++)
		m_Dynamics[i]->draw(window, passedTime);
	if(gotShot)
		window.draw(m_screens[BLOOD]);

	if (m_pab->canShoot())
		for (int i = 0; i < m_Bullet.size(); i++) {
			m_Bullet[i]->draw(window, passedTime);
	}

	if (m_pab->getBomb())
	{
		for (int i = 0; i < m_Bomb.size(); i++) {
			m_Bomb[i]->draw(window, m_Bomb[i]->getpos());
		//	m_Bomb.pop_back();
		}
	}
	//todo
	//window.draw(m_screens[EXPLOSION]);
}

//-----------------------------------------------------------------------------
// move Dynamic objects
void Controller::moveDynamic(sf::RenderWindow & window, sf::Clock &clock)
{
	checkCollision();

	for (int i = 0; i < m_Dynamics.size(); i++)
		m_Dynamics[i]->move(clock, m_level.getBoardSize());

	if(m_pab->canShoot())
	for (int i = 0; i < m_Bullet.size(); i++)
		m_Bullet[i]->move(clock, m_level.getBoardSize());
	
	if (m_pab->getBomb())
	{
		if (counter1 == 0 && m_Bomb.size() > 0)
		{
			drawBomb(window);
			counter1 = 1;
		}
	}

}

//-----------------------------------------------------------------------------
// set Direction and gey key
void Controller::setDirection(sf::Event newEvent, sf::Clock & clock)
{
	//  checks if in air mode , press up = go upstairs else jump
	if (isFire) {
		m_pab->rotatePlayer(5);
		isFire = false;
	}
	if (newEvent.key.code == sf::Keyboard::Space && !isJump)
	{
		m_pab->setSpeedValue(data.jumpF / m_pab->getMass());
		isJump = true;
		isMoving = true;
		setPabloDirection(newEvent.key.code);
	}

	if ((newEvent.key.code == sf::Keyboard::P) && (m_pab->getBomb()))
		doBomb();


	if (m_pab->canShoot()) {
		if ((newEvent.key.code == sf::Keyboard::Return))
		{
			m_Bullet.emplace_back(m_pab->shooting());
			setPabloDirection(newEvent.key.code);
			isMoving = true;
			isFire = true;
			if (isFire) {
				m_pab->rotatePlayer(-5);
			}
		}
	}
			
	if (newEvent.key.code == sf::Keyboard::Left /*|| newEvent.key.code == sf::Keyboard::Up*/ ||
		/*newEvent.key.code == sf::Keyboard::Down ||*/ newEvent.key.code == sf::Keyboard::Right)
	{
		setPabloDirection(newEvent.key.code);
		isMoving = true;
	}

}
//-----------------------------------------------------------------------------
// take care of bomb
void Controller::doBomb()
{
	sf::Vector2f bP;
	bP.x = m_pab->getPosition().x + 40;
	bP.y = m_pab->getPosition().y + 10;

	m_Bomb.emplace_back(FactoryStatic::Create('T'));
	m_Bomb.back()->setPOS(bP);
	m_pab->SetCounters()._TNT--;
	counter1 = 0;
}
//-----------------------------------------------------------------------------
// draw after bomb
void Controller::drawBomb(sf::RenderWindow & window)
{
	std::string afterBomb;
	float time = 0;
	float dale = 3.0f;
	sf::Clock clock;
	clock.restart();
	m_getReady.setColor(sf::Color::White);
	m_getReady.setCharacterSize(WINDOW_HEIGHT / 15);
	m_getReady.setOutlineColor(sf::Color::Blue);
	m_getReady.setOutlineThickness(3);

	sf::Vector2f p;
	p.x = m_Bomb.back()->getpos().x;
	p.y = m_Bomb.back()->getpos().y +5;

	m_screens[EXPLOSION].setPosition(p);

	m_sound[SURPRISE_SOUND].play();
	for (int i = 0; i < 3;)
	{
		afterBomb = "B O M B!  " + std::to_string(3 - i);
		time += clock.getElapsedTime().asSeconds();
		draw(window, dale);
		m_getReady.setPosition(p);

		m_getReady.setString(afterBomb);
		window.draw(m_getReady);
		window.display();
		window.clear();
		if (time >= 45)
		{
			i++;
			time = 0;
			clock.restart();
		}
	}
	window.draw(m_screens[EXPLOSION]);
	m_sound[EXPLO_SOUND].play();
}
//-----------------------------------------------------------------------------
// checks the event along the game
void Controller::checkEvent(sf::RenderWindow & window, sf::Clock & clock, sf::Event Event)
{
	switch (Event.type)
	{
	case sf::Event::Closed:
		window.close();
		break;

	case sf::Event::KeyPressed:
	{
		Cheats(Event.key.code);
		switch (Event.key.code)
		{
		case sf::Keyboard::O:
			GameMusic.setVolume(GameMusic.getVolume() + 10);
			break;
		case sf::Keyboard::P:
			GameMusic.setVolume(GameMusic.getVolume() - 10);
			break;
		case sf::Keyboard::S:
			mute(GameMusic);
			break;
		case sf::Keyboard::L:
			m_lifeCheat = std::to_string(sf::Keyboard::L);
			break;
		case sf::Keyboard::M:
			m_pointsCheat = std::to_string(sf::Keyboard::M);
			break;
		case sf::Keyboard::D:
			m_airCheat = std::to_string(sf::Keyboard::D);
			break;
		}	

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			m_pab->StandDirection(UP);
			m_pab->jump();
		}
		setDirection(Event, clock);
		//m_pab->move(, m_level.getBoardSize());
		break;
	}

	case sf::Event::KeyReleased: {
		 m_pab->StandDirection(NONE);
		//isMoving = false;

		 break;
	}
	}
}
//-----------------------------------------------------------------------------
// set Dynamics obj.
void Controller::setDynamics(sf::RenderWindow & window)
{
	m_pab->SetPosition(m_pab->getStartingPosition());
	//for (size_t i = 0; i < m_pcptr.size(); i++)
	//	m_pcptr[i]->SetPosition(m_pcptr[i]->getStartingPosition());
	m_pab->setPabloState();
	isMoving = false;
}
//-----------------------------------------------------------------------------
// checks if the object is oyt of board
bool Controller::OutOfBoard(sf::Vector2f place, const vector<vector<std::unique_ptr<StaticIcon>>>& board)
{
	return !(place.x < 0 || place.y < 0
		|| place.x >= board[0].size() ||
		place.y >= board.size());
}
//-----------------------------------------------------------------------------
// take care of enemy 
void Controller::checkEnemy(sf::RenderWindow & window)
{

	if(m_pcm_first&& pcm_counter < 4){
	//	m_pcptr.emplace_back(m_pab.CreatePCM());
		//pcm_counter++;
		gap -= 200;
	}
	m_pcm_first = false;
}

//-----------------------------------------------------------------------------
// take care of Player
void Controller::checkPlayer()
{
	//checkColiision - Todo !!
 	if (isJump) {
		//m_pab.jump(0.015);
		checkCollision();

		// if you're walking on ground now
		if (m_pab->getPosition().y > m_pab->get_current_ground_y()) {
			sf::Vector2f new_pos;
			new_pos.x = m_pab->getPosition().x;
			//new_pos.y = m_pab.get_current_ground_y();//todo
			new_pos.y = m_pab->getPosition().x - 0.05f ; // change
			new_pos.y = 15.f; // change

			m_pab->SetPosition(new_pos);
			isJump = false;
			m_pab->setAccelerationValue(0);
		}
	}
}
//-----------------------------------------------------------------------------
// check For High score 
bool Controller::checkForHs(int highScores[], int score, int & index)
{
	for (int i = 0; i < NUM_OF_SCORES; i++)
	{
		if (score > highScores[i])
		{
			highScores[i] = score;
			index = i;
			return true;
		}
	}
	return false;
}
//-----------------------------------------------------------------------------
// Cheats along the game
void Controller::Cheats(sf::Keyboard::Key key)
{
	sf::Sprite prev_s = m_pab->getSprite();

	m_lifeCheat += std::to_string(key);
	m_pointsCheat += std::to_string(key);
	m_airCheat += std::to_string(key);
	if (m_lifeCheat == LIFE_CHEAT)
		m_pab->setLife(1);
	if (m_pointsCheat == SCORE_CHEAT)
		m_pab->setScore(50);
	if (m_airCheat == AIR_CHEAT) {
		m_pab->airPlane();
		m_pab->getSprite() = prev_s;
	}

}
//-----------------------------------------------------------------------------
// mute the game sound
void Controller::mute(sf::Music & GameMusic)
{
	if (m_mute)
	{
		GameMusic.setVolume(100);
		m_mute = false;
	}
	else
	{
		GameMusic.setVolume(0);
		m_mute = true;
	}
}
