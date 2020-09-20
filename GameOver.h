#pragma once
#include <string>
#include "BaseState.h"

class Game;
class GameOver : public BaseState
{
	int mMaxOption;
	int mOption;
	Game* mGame;
public:
	GameOver(Game* lGame);
	~GameOver();

	std::string GetString();

	void MovePointerLeft();
	void MovePointerRight();
	void Enter();

	void OnActivate();
	void OnDeactivate();
};