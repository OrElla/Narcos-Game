#include "JumpingState.h"
#include "AttackingState.h"


JumpingState::JumpingState()
{
}


JumpingState::~JumpingState()
{
}

unique_ptr<State> JumpingState::handleInput(INPUT input)
{
	if (input == PRESS_DOWN)
		return make_unique<AttackingState>();

	return NULL;

}

void JumpingState::enter(Pablo & Pablo)
{
	//mario.setGraphics(IMAGE_JUMP);
	//start a timer for the jump  
}
