#include "StateManager.h"

StateManager::StateManager()
{
	mCurrentState = State::Menu;
}

StateManager::~StateManager()
{
}

bool StateManager::AddState(State lState, BaseState * lPointer)
{
	if (mStates.find(lState) != mStates.end())//duplicate state exist
	{
		return 0;
	}

	mStates.emplace(lState, lPointer);
	return 1;
}

State StateManager::GetState()
{
	return mCurrentState;
}

void StateManager::SetState(State lState)
{
	mStates[mCurrentState]->OnDeactivate();
	mStates[lState]->OnActivate();
	mCurrentState = lState;
}
