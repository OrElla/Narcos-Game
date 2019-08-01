#pragma once
#include "State.h"

class AttackingState : public State
{
public:
	AttackingState();

	unique_ptr<State> handleInput(INPUT input);
	virtual void enter(Pablo& pablo);
	~AttackingState();
};

