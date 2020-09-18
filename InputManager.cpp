#include "InputManager.h"
#include "Game.h"

InputManager::InputManager(Game *lGame)
	: mGame(lGame)
{
}

InputManager::~InputManager()
{
}

void InputManager::HandleInput(){
	mInput = _getch();
	if(mGame->mStateManager.GetState() == State::Menu){
		InputForMenu();
	}
	else if(mGame->mStateManager.GetState() == State::Game){
		InputForGame();
	}
}

void InputManager::InputForMenu(){
	if(mInput == 'w'){
		mGame->mMenu.MovePointerUp();
	}
	else if(mInput == 's'){
		mGame->mMenu.MovePointerDown();
	}
	else if(mInput == EnterCode){
		mGame->mMenu.Enter();
	}
}

void InputManager::InputForGame(){
	if(mInput == 'w'){
		mGame->mMap.GoUp();
	}
	else if(mInput == 's'){
		mGame->mMap.GoDown();
	}
	else if(mInput == 'a'){
		mGame->mMap.GoLeft();
	}
	else if(mInput == 'd'){
		mGame->mMap.GoRight();
	}
	else if (mInput == 'm')
	{
		mGame->mMap.ToggleViewDistance();
	}
}
