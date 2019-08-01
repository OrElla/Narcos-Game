#pragma once
#include "State.h"
#include "StandingState.h"
#include "AttackingState.h"


class RightWalking : public State
{
public:
	RightWalking();

	unique_ptr<State> handleInput(INPUT input)  override;
	void enter(Pablo& Pablo);
	~RightWalking();
};

