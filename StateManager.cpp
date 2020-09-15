#include "StateManager.h"

StateManager::StateManager()
{
	mCurrentState = State::Menu;
}

StateManager::~StateManager()
{
}

State StateManager::GetState()
{
	return mCurrentState;
}

void StateManager::SetState(State lState)
{
	mCurrentState = lState;
}
