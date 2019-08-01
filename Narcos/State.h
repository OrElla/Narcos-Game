#pragma once
#include <memory>
#include <vector>
#include <algorithm>


using namespace std;
class Pablo;

enum INPUT {
	PRESS_UP,PRESS_LEFT,PRESS_RIGHT, PRESS_DOWN,
	PRESS_SPACE, RELEASE_RIGHT, RELEASE_LEFT
};


class State {
public:

	State() = default;
	virtual ~State() { }

	virtual unique_ptr<State>handleInput(INPUT input) = 0;
	virtual void enter(Pablo& Pablo) = 0;
}; 

