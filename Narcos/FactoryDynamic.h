#pragma once
#include "DynamicIcon.h"
#include <memory>
#include <map>
#include "Map.h"
//#include <vector>

class Bullet;
class PoliceMan;

class FactoryDynamic 
{
public:
	FactoryDynamic();

	static std::shared_ptr<DynamicIcon>Create(const char & c);
	std::shared_ptr<DynamicIcon> CreateBullets(const char & c, sf::Vector2f pos, bool left);
	std::shared_ptr<DynamicIcon> CreatePoliceMan(const char & c, sf::Vector2f pos);

	static bool registerIt(const char &c, std::shared_ptr<DynamicIcon >(*f)());
	~FactoryDynamic();


private:

	//vector <std::unique_ptr<Bullet>> sCreate(const char & c);

};


