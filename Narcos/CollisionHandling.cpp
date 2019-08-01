#include "CollisionHandling.h"
#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>
#include "Pablo.h"
#include "Ground1.h"
#include "Coin.h"
#include "Money.h"
#include "MoneyBag.h"
#include "Coc.h"
#include "Gun.h"
#include "Weed.h"
#include "Food.h"
#include "Knife.h"
#include "TNT.h"
#include "Energy.h"
#include "Beer.h"
#include "PoilceStation.h"
#include "Cave.h"
#include "Animal.h"
#include "PoliceMan.h"
#include "Bullet.h"
#include "Bird.h"

sf::Sound sound[NUM_OF_SOUNDS];
sf::Sprite screen[NUM_OF_SCREENS];

//colison pcm with bullet or pablo with bullet
// +sound
// colision with pcm station - sprite +sound +time;

namespace { // unnamed namespace — the standard way to make function "static"

			// primary collision-processing functions
	

	void pabloGround(Tile& pablo, Tile& ground)
	{
		Pablo& p = static_cast<Pablo&>(pablo);
		Ground1& g = static_cast<Ground1&>(ground);
		p.collideGround(g);
		p.setcollideground(true);
	}

	void policeStation_Tnt(Tile& PCS, Tile& tnt)
	{
		PoilceStation& p = static_cast<PoilceStation&>(PCS);
		TNT& g = static_cast<TNT&>(tnt);
		PCS.setExist(false);
		std::cout << "jojojoj";
	}


	void pabloCave(Tile& pablo,
		Tile& cave)
	{
		Pablo& p = static_cast<Pablo&>(pablo);
		PabloInCave(p);

		std::cout << "SpaceShip and SpaceStation collision!" << std::endl;
	}

	void pabloPoliceStation(Tile& pablo, Tile& policestation)
	{
		Pablo& p = static_cast<Pablo&>(pablo);
		//p.collideGround(Ground1());
		pabloGround(pablo, policestation);
	}

	void PoliceStationPablo(Tile& policestation, Tile& pablo)
	{
		Pablo& p = static_cast<Pablo&>(pablo);
		pabloGround(pablo, policestation);
	}


	void pabloGun(Tile& pablo, Tile& gun)
	{
		Pablo& p = static_cast<Pablo&>(pablo);
		gun.setExist(false);
		p.SetCounters()._Bullet+=2;
	}

	void pabloBird(Tile& pablo, Tile& bird)
	{
		Pablo& p = static_cast<Pablo&>(pablo);
		//p.setLife(3);
		
		p.SetCounters()._Energy--;
		if (p.SetCounters()._Energy == 0)
		{
			p.decLife();
			if(p.getLife() !=0)
			p.setEnergy(5);
		}
	}

	void pabloPcm(Tile& pablo, Tile& pcm)
	{
		Pablo& p = static_cast<Pablo&>(pablo);
		if (p.getcollidepoliceman())	
		{
			PabloPoliceMan(p);
			p.setvolecity();
		}
		p.setcollidepoliceman(false);
	}

	void PcmPcm(Tile& p1, Tile& p2)
	{
		//PoliceMan& p = static_cast<PoliceMan&>(p1);
		//	PabloPoliceMan(p);
	}



	void policemanGround(Tile& policeman, Tile& ground)
	{
		PoliceMan & p = static_cast<PoliceMan&>(policeman);
		Ground1& g = static_cast<Ground1&>(ground);
		p.collideGround(g);
	}
	void birdGround(Tile& bird, Tile& ground)
	{
		Bird & b = static_cast<Bird&>(bird);
		Ground1& g = static_cast<Ground1&>(ground);
		b.collideGround(g);
	}

	void policemanBullet(Tile& policeman, Tile& bullet)
	{
		PoliceMan & p = static_cast<PoliceMan&>(policeman);
		p.decLife();
	}
	void birdBullet(Tile& bird, Tile& bullet)
	{
		Bird & b = static_cast<Bird&>(bird);
		b.decLife();
	}
	

	void pabloBullet(Tile& pablo, Tile& bullet)
	{
		Pablo & p = static_cast<Pablo&>(pablo);
		p.SetCounters()._Energy -= 1;
		if (p.SetCounters()._Energy == 0) {
			p.decLife();
			if(p.getLife() != 0)
			p.setEnergy(5);
		}
	}

	void pabloCoin(Tile& pablo, Tile& coin)
	{
		sound[COINS].setBuffer(*(FileManager::getInstance().getGameSound(COINS)));
		sound[COINS].setVolume(75);
		sound[COINS].play();

		coin.setExist(false);
		Pablo& p = static_cast<Pablo&>(pablo);
		p.SetCounters()._Coin++;
	}
	void pabloWeed(Tile& pablo, Tile& weed)
	{
		sound[SNIFFING].setBuffer(*(FileManager::getInstance().getGameSound(SNIFFING)));
		sound[SNIFFING].setVolume(75);
		sound[SNIFFING].play();
		weed.setExist(false);
		Pablo& p = static_cast<Pablo&>(pablo);
		p.SetCounters()._Weed++;
	}

	void pabloFood(Tile& pablo, Tile& food)
	{
		sound[EATING_SOUND].setBuffer(*(FileManager::getInstance().getGameSound(EATING_SOUND)));
		sound[EATING_SOUND].setVolume(75);
		sound[EATING_SOUND].play();

		food.setExist(false);
		Pablo& p = static_cast<Pablo&>(pablo);
		p.SetCounters()._Food++;
	}

	void pabloKnife(Tile& pablo, Tile& knife)
	{
		sound[KNIFE_SOUND].setBuffer(*(FileManager::getInstance().getGameSound(KNIFE_SOUND)));
		sound[KNIFE_SOUND].setVolume(75);
		sound[KNIFE_SOUND].play();
		knife.setExist(false);
		Pablo& p = static_cast<Pablo&>(pablo);
		p.SetCounters()._Knife++;
	}

	void pabloTNT(Tile& pablo, Tile& tnt)
	{
		tnt.setExist(false);
		Pablo& p = static_cast<Pablo&>(pablo);
		p.SetCounters()._TNT++;
	}

	void pabloEnergy(Tile& pablo, Tile& energy)
	{
		energy.setExist(false);
		Pablo& p = static_cast<Pablo&>(pablo);
		if(p.SetCounters()._Energy < 5)
		p.SetCounters()._Energy++;
	}

	void pabloBeer(Tile& pablo, Tile& beer)
	{
		beer.setExist(false);
		Pablo& p = static_cast<Pablo&>(pablo);
		p.SetCounters()._Beer++;
	}


	void pabloMoney(Tile& pablo, Tile& money)
	{
		sound[MONEY_s].setBuffer(*(FileManager::getInstance().getGameSound(MONEY_s)));
		sound[MONEY_s].setVolume(75);
		sound[MONEY_s].play();

		money.setExist(false);
		Pablo& p = static_cast<Pablo&>(pablo);
		p.SetCounters()._Money++;	
	}

	void pabloMoneyBag(Tile& pablo, Tile& moneybag)
	{
		sound[MONEY_BAG_s].setBuffer(*(FileManager::getInstance().getGameSound(MONEY_BAG_s)));
		sound[MONEY_BAG_s].setVolume(75);
		sound[MONEY_BAG_s].play();

		moneybag.setExist(false);
		Pablo& p = static_cast<Pablo&>(pablo);
		p.SetCounters()._MoneyBag++;
	}

	void PcmPs(Tile& Pcm, Tile& Ps)
	{
		//
	}
	
	void PcmBird(Tile& Pcm, Tile& bird){
		//
	}

	void PoliceStationBird(Tile& Pcm, Tile& bird){
		//
	}
	void BirdPoliceStation(Tile& b, Tile& p) {
		//
	}
	


	void pabloCoc(Tile& pablo, Tile& coc)
	{
		coc.setExist(false);
		Pablo& p = static_cast<Pablo&>(pablo);
		p.SetCounters()._Coc+=1;
		if ((p.SetCounters()._Coc % 3) == 0)
			PabloSmoking(p);
	}

	// secondary collision-processing functions that just
	// implement symmetry: swap the parameters and call a
	// primary function
	void groundPablo(Tile& p,
		Tile& g)
	{
		pabloGround(g, p);
	}

	using HitFunctionPtr = void(*)(Tile&, Tile&);
	using Key = std::pair<std::type_index, std::type_index>;
	using HitMap = std::map<Key, HitFunctionPtr>;

	HitMap initializeCollisionMap()
	{
		HitMap phm;
		phm[Key(typeid(Pablo), typeid(Ground1))] = &pabloGround;
		phm[Key(typeid(Pablo), typeid(Cave))] = &pabloCave;
		phm[Key(typeid(Pablo), typeid(Money))] = &pabloMoney;
		phm[Key(typeid(Pablo), typeid(MoneyBag))] = &pabloMoneyBag;
		phm[Key(typeid(Pablo), typeid(Coin))] = &pabloCoin;
		phm[Key(typeid(Pablo), typeid(Coc))] = &pabloCoc;
		phm[Key(typeid(Pablo), typeid(Food))] = &pabloFood;
		phm[Key(typeid(Pablo), typeid(Knife))] = &pabloKnife;
		phm[Key(typeid(Pablo), typeid(Weed))] = &pabloWeed;
		phm[Key(typeid(Pablo), typeid(TNT))] = &pabloTNT;
		phm[Key(typeid(Pablo), typeid(Energy))] = &pabloEnergy;
		phm[Key(typeid(Pablo), typeid(Beer))] = &pabloBeer;
		phm[Key(typeid(Pablo), typeid(Gun))] = &pabloGun;
		phm[Key(typeid(Pablo), typeid(PoilceStation))] = &pabloPoliceStation;
		phm[Key(typeid(PoliceMan), typeid(Ground1))] = &policemanGround;
		phm[Key(typeid(Bird), typeid(Ground1))] = &birdGround;

		phm[Key(typeid(Bird), typeid(Bullet))] = &birdBullet;
		phm[Key(typeid(PoliceMan), typeid(Bullet))] = &policemanBullet;
		phm[Key(typeid(Pablo), typeid(Bullet))] = &pabloBullet;
		phm[Key(typeid(Pablo), typeid(Bird))] = &pabloBird;
		phm[Key(typeid(Pablo), typeid(PoliceMan))] = &pabloPcm;
		phm[Key(typeid(PoliceMan), typeid(PoliceMan))] = &PcmPcm;
		phm[Key(typeid(PoliceMan), typeid(PoilceStation))] = &PcmPs;
		phm[Key(typeid(PoliceMan), typeid(Bird))] = &PcmBird;
		phm[Key(typeid(PoilceStation), typeid(Pablo))] = &PoliceStationPablo;
		
		phm[Key(typeid(PoilceStation), typeid(Bird))] = &PoliceStationBird;
		phm[Key(typeid(Bird), typeid(PoilceStation))] = &BirdPoliceStation;

		
		//todo
		phm[Key(typeid(PoilceStation), typeid(TNT))] = &policeStation_Tnt;
		phm[Key(typeid(TNT), typeid(PoilceStation))] = &policeStation_Tnt;

		
		return phm;
	}

	HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
	{
		static HitMap collisionMap = initializeCollisionMap();
		auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
		if (mapEntry == collisionMap.end())
		{
			return nullptr;
		}
		return mapEntry->second;
	}

} // end namespace

void processCollision(Tile& object1, Tile& object2)
{
	auto phf = lookup(typeid(object1), typeid(object2));
	if (!phf)
	{
		throw UnknownCollision(object1, object2);
	}
	phf(object1, object2);
}

void PabloInCave(Pablo& p)
{
	sf::Clock cave_clock;
	float time = 5;
	int coins = 0;
	
	screen[CaveS].setTexture(*(FileManager::getInstance().getScreen(CaveS)));
	sf::RenderWindow CaveWINDOW;
	CaveWINDOW.create(sf::VideoMode(WINDOW_LENGTH, WINDOW_HEIGHT), "CAVE");
	
	sf::Vector2f prev = p.getPosition();

	sf::Vector2f p_pos;
	p_pos.x = CaveWINDOW.getSize().x / 2 - 180;
	p_pos.y = CaveWINDOW.getSize().y / 2;

	cave_clock.restart();
	while (CaveWINDOW.isOpen())
	{
		p.SetPosition(p_pos);
		sf::Event Event;
		while (CaveWINDOW.pollEvent(Event))
			if (Event.type == sf::Event::Closed || coins == FULL_COINS
				|| (cave_clock.getElapsedTime().asSeconds() >= time))
				CaveWINDOW.close();


		CaveWINDOW.draw(screen[CaveS]);
		CaveWINDOW.draw(p.getSprite());
		CaveWINDOW.display();
		CaveWINDOW.clear();
	}
	p.SetPosition(prev);
}

void PabloSmoking(Pablo & p)
{
	sf::Clock smoking_clock;
	smoking_clock.restart();
	sf::RenderWindow SmokeWINDOW;
	screen[SMOKING_A].setTexture(*(FileManager::getInstance().getScreen(SMOKING_A)));
	SmokeWINDOW.create(sf::VideoMode(500, 500), "SMOKING");

	//wants smoking break??
		int answer = rand() % 2;

		sound[SMOKING].setBuffer(*(FileManager::getInstance().getGameSound(SMOKING)));
		sound[SMOKING].setVolume(75);
		sound[SMOKING].play();

		float smokingTime = 4.f;
		while (SmokeWINDOW.isOpen())
		{
			std::cout << smoking_clock.getElapsedTime().asSeconds() << std::endl;
			sf::Event Event;
			while (SmokeWINDOW.pollEvent(Event))
				if (Event.type == sf::Event::Closed)
					SmokeWINDOW.close();

			if (smoking_clock.getElapsedTime().asSeconds() > smokingTime)
				SmokeWINDOW.close();
			SmokeWINDOW.draw(screen[SMOKING_A]);
			SmokeWINDOW.display();
			SmokeWINDOW.clear();
		}
}

void PabloPoliceMan(Pablo & p)
{
	sf::RenderWindow PCM_WINDOW;
	PCM_WINDOW.create(sf::VideoMode(500, 500), "PCM");
	int answer = rand() % 2;
	sf::Clock pcm_clock;
	float passed = 3.f;
	
	screen[PAB_SHOOT].setTexture(*(FileManager::getInstance().getScreen(PAB_SHOOT)));
	screen[Coli_pol].setTexture(*(FileManager::getInstance().getScreen(Coli_pol)));
	
	screen[PAB_SHOOT].setScale(1.0f, ((float)PCM_WINDOW.getSize().y /
		(FileManager::getInstance().getScreen(PAB_SHOOT))->getSize().y));

	screen[Coli_pol].setScale(1.0f, ((float)PCM_WINDOW.getSize().y /
		(FileManager::getInstance().getScreen(Coli_pol))->getSize().y));


	sound[PLATO_O_PLOMO].setBuffer(*(FileManager::getInstance().getGameSound(PLATO_O_PLOMO)));
	sound[PLATO_O_PLOMO].setVolume(100);
	sound[PLATO_O_PLOMO].play();
	pcm_clock.restart();

	sf::Vector2f pab_p;
	pab_p.x = p.getPosition().x -30;
	pab_p.y = p.getPosition().y-30;
	answer = 0;
	while (PCM_WINDOW.isOpen())
	{
		if (pcm_clock.getElapsedTime().asSeconds() <= passed)
			PCM_WINDOW.draw(screen[Coli_pol]);

		if (pcm_clock.getElapsedTime().asSeconds() > passed)
		{
			if (answer == 0)
			{
				//std::cout << "plomo";
				PCM_WINDOW.draw(screen[PAB_SHOOT]);
				p.getSprite().setPosition(pab_p);
				if (pcm_clock.getElapsedTime().asSeconds() > 2+passed)
					PCM_WINDOW.close();
			}
			else
			{
				p.setScore(-10);
				p.getSprite().setPosition(pab_p);
				PCM_WINDOW.close();
			}
		}

		sf::Event Event;
		while (PCM_WINDOW.pollEvent(Event))
			if (Event.type == sf::Event::Closed)
				PCM_WINDOW.close();
		/*	
		if (pcm_clock.getElapsedTime().asSeconds() > passed
			&&pcm_clock.getElapsedTime().asSeconds() < 2 + passed)
		{
			if (answer == 0) {
				std::cout << "plomo\n";
				PCM_WINDOW.draw(screen[PAB_SHOOT]);
				p.getSprite().move(35, -30);
			}
			else {
				std::cout << "plato\n";
				p.getSprite().move(35, -30);
			}
		}
		else
		{
			p.getSprite().move(35, -30);
			PCM_WINDOW.close();
		}
		*/
		PCM_WINDOW.display();
		PCM_WINDOW.clear();
	}
}

