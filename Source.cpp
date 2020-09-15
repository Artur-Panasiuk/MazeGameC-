#include "Game.h"

int main()
{
	Game mGame;
	while (mGame.IsOpen())
	{
		mGame.WriteOutput();
		mGame.HandleInput();
	}
}