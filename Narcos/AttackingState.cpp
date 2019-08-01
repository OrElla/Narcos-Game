#include "AttackingState.h"



AttackingState::AttackingState()
{
}

unique_ptr<State> AttackingState::handleInput(INPUT input)
{
	return NULL;

}

void AttackingState::enter(Pablo & pablo)
{
	{
		//pablo.setGraphics(IMAGE_ATTACK);
		//start a timer for the attack  
	}
}


AttackingState::~AttackingState()
{
}
