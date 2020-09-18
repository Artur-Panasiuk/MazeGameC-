#pragma once
#include "BaseState.h"

class Game;
class GameOver : public BaseState
{
	Game* mGame;
public:
	GameOver(Game* lGame);
	~GameOver();

	void OnActivate();
	void OnDeactivate();
};