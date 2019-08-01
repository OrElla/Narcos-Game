#include "RightWalking.h"



RightWalking::RightWalking()
{
}

unique_ptr<State> RightWalking::handleInput(INPUT input)
{
	if (input == RELEASE_RIGHT)
	{
		return make_unique<StandingState>();
	}
	if (input == PRESS_SPACE)
	{
		return make_unique<AttackingState>();
	}
}

void RightWalking::enter(Pablo & Pablo)
{
	//
}


RightWalking::~RightWalking()
{
}
