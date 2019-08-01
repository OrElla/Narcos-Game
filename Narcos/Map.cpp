#include "Map.h"


// map class controlled for the game 

Map::Map()
{
}


std::map<char, std::shared_ptr<StaticIcon>(*)()>& Map::getMapStatic()
{
	static std::map<char, std::shared_ptr<StaticIcon>(*)()>m_map;
	return m_map;
}

std::map<char, std::shared_ptr<DynamicIcon>(*)()>& Map::getMapDynamic()
{
	static std::map<char, std::shared_ptr<DynamicIcon>(*)()>m_map;
	return m_map;
}

Map & Map::getInsMap()
{
	static Map instance;
	return instance;
}

Map::~Map()
{
}
