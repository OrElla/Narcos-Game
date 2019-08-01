#pragma once

#include "Tile.h"
#include <memory>
#include <iostream>
#include <typeinfo>

// Sample struct for exception throwing
struct UnknownCollision
{
	UnknownCollision(Tile& a, Tile& b) : first(a), second(b)
	{
		std::cout << "Unkown collision of " << typeid(a).name() << " and "
			<< typeid(b).name() << std::endl;
	}
	Tile& first;
	Tile& second;
};

void processCollision(Tile& object1, Tile& object2);
void PabloInCave(Pablo& p);
void PabloSmoking(Pablo& p);
void PabloPoliceMan(Pablo& p);

