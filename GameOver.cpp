#include "GameOver.h"
#include "Game.h"

GameOver::GameOver(Game* lGame)
	: mGame(lGame)
{
	mGame->mStateManager.AddState(State::GameOver, this);
}

GameOver::~GameOver()
{
}

void GameOver::OnActivate()
{
}

void GameOver::OnDeactivate()
{
}
