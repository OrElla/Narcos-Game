#pragma once
#include "State.h"

class StandingState : public State {
public:
	~StandingState();
	StandingState();
	unique_ptr<State> handleInput(INPUT input);
	virtual void enter(Pablo& pablo);
};
