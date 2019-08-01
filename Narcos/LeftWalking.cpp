#include "LeftWalking.h"



LeftWalking::LeftWalking()
{
}

unique_ptr<State> LeftWalking::handleInput(INPUT input)
{
	if (input == RELEASE_LEFT)
	{
		return make_unique<StandingState>();
	}
}

void LeftWalking::enter(Pablo & Pablo)
{
}


LeftWalking::~LeftWalking()
{
}
