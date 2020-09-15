#pragma once
#include "State.h"

class StateManager
{
	State mCurrentState;
public:
	StateManager();
	~StateManager();

	State GetState();
	void SetState(State lState);
};