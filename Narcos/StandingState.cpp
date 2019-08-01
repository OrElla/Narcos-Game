#include "StandingState.h"
#include "JumpingState.h"
#include "RightWalking.h"
#include "LeftWalking.h"
#include "AttackingState.h"


StandingState::StandingState()
{
}


StandingState::~StandingState()
{
}

unique_ptr<State> StandingState::handleInput(INPUT input)
{
	switch (input)
	{
	case PRESS_UP: 
		return make_unique<JumpingState>();
	case PRESS_RIGHT:
		return make_unique<RightWalking>(); 
	case PRESS_LEFT:
		return make_unique<LeftWalking>();
	case PRESS_SPACE:
		return make_unique<AttackingState>();

	default:
		break;
	}

	// Stay in this state.
	return NULL;
}

void StandingState::enter(Pablo & pablo)
{
	//mario.setGraphics(IMAGE_STAND);
}
