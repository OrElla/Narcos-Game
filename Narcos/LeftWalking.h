#pragma once
#include "State.h"
#include "StandingState.h"

class LeftWalking : public State
{
public:
	LeftWalking();

	unique_ptr<State> handleInput(INPUT input)  override;
	void enter(Pablo& Pablo);

	~LeftWalking();
};

