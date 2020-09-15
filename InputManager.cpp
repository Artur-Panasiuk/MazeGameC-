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

	}
	else if(mInput == 's'){

	}
	else if(mInput == 'a'){

	}
	else if(mInput == 'd'){
		
	}
}
