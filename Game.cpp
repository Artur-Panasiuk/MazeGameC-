#include "Game.h"

Game::Game()
	: mIsOpen(true), mInputManager(this), mOutputManager(this), mMenu(this), mMap(this)
{
}

Game::~Game()
{
}

bool Game::IsOpen()
{
	return mIsOpen;
}

void Game::EndGame()
{
	mIsOpen = false;
}

void Game::WriteOutput()
{
	mOutputManager.WriteOutput();
}

void Game::HandleInput()
{
	mInputManager.HandleInput();
}

void Game::Update()
{
	if (mStateManager.GetState() == State::Game)
	{
		mMap.Update();
	}
}
