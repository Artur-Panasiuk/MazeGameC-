#pragma once
#include "State.h"
#include "BaseState.h"
#include <unordered_map>

class StateManager
{
	State mCurrentState;

	std::unordered_map<State, BaseState*> mStates;
public:
	StateManager();
	~StateManager();

	bool AddState(State lState, BaseState* lPointer);

	State GetState();
	void SetState(State lState);
};