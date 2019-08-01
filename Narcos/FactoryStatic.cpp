#include "FactoryStatic.h"

//creating Static icons


FactoryStatic::FactoryStatic()
{
}

std::shared_ptr<StaticIcon> FactoryStatic::Create(const char & c)
{
	auto it = Map::getInsMap().getMapStatic().find(c);
	if (it == Map::getInsMap().getMapStatic().end())
		return nullptr;
	return it->second();
}

bool FactoryStatic::registerIt(const char & c, std::shared_ptr<StaticIcon>(*f)())
{
	Map::getInsMap().getMapStatic().emplace(c,f);
	return true;
}


FactoryStatic::~FactoryStatic()
{
}
