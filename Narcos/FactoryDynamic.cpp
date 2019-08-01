#include "FactoryDynamic.h"
#include "Bullet.h"
#include "PoliceMan.h"
#include "Bird.h"

//creating dynamic icons

FactoryDynamic::FactoryDynamic()
{
}


std::shared_ptr<DynamicIcon> FactoryDynamic::Create(const char & c)
{
	auto it = Map::getInsMap().getMapDynamic().find(c);
	if (it == Map::getInsMap().getMapDynamic().end())
		return nullptr;
	return it->second();
}

std::shared_ptr<DynamicIcon> FactoryDynamic::CreateBullets(const char & c, sf::Vector2f pos, bool left)
{

	std::shared_ptr<DynamicIcon> m_bull = std::move(Create(c));
	m_bull->SetPosition(pos);

	return std::move(m_bull);
}

std::shared_ptr<DynamicIcon> FactoryDynamic::CreatePoliceMan(const char & c, sf::Vector2f pos)
{
	std::shared_ptr<DynamicIcon> m_pcm = std::move(Create(c));
	m_pcm->SetPosition(pos);

	return std::move(m_pcm);
}



bool FactoryDynamic::registerIt(const char & c, std::shared_ptr<DynamicIcon>(*f)())
{
	Map::getInsMap().getMapDynamic().emplace(c, f);
	return true;
}


FactoryDynamic::~FactoryDynamic()
{
}
