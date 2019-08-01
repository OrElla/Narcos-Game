#pragma once
#include "State.h"

class JumpingState : public State
{
public:
	JumpingState();
	~JumpingState();

	unique_ptr<State> handleInput(INPUT input)  override;
	void enter(Pablo& Pablo);

};

