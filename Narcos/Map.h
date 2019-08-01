#pragma once
#include "StaticIcon.h"
#include "DynamicIcon.h"

class Map
{
public:
	
	static std::map<char, std::shared_ptr<StaticIcon>(*)()>&getMapStatic();
	static std::map<char, std::shared_ptr<DynamicIcon>(*)()>&getMapDynamic();

	static Map & getInsMap();
	
private:
	Map(Map &) = delete;
	Map();
	~Map();
};

