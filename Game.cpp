#include "Game.h"

Game::Game()
	: mIsOpen(true), mInputManager(this), mOutputManager(this)
{
}

Game::~Game()
{
}

bool Game::IsOpen()
{
	return mIsOpen;
}

void Game::WriteOutput()
{
	mOutputManager.WriteOutput();
}

void Game::HandleInput()
{
	mInputManager.HandleInput();
}
