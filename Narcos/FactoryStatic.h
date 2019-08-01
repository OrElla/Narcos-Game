#pragma once
#include "StaticIcon.h"
#include <memory>
#include <map>
#include "Map.h"

class FactoryStatic
{
public:
	FactoryStatic();

	static std::shared_ptr<StaticIcon>Create(const char & c);
	static bool registerIt(const char &c, std::shared_ptr<StaticIcon >(*f)());
private:
	~FactoryStatic();
};


