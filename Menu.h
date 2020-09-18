#pragma once
#include <string>
#include "BaseState.h"

class Game;
class Menu : public BaseState
{
	int mOption;
	const int mOptionMax;

	Game* mGame;
public:
	Menu(Game* lGame);
	~Menu();

	std::string GetString();

	void MovePointerUp();
	void MovePointerDown();

	void Enter();

	void OnActivate();
	void OnDeactivate();
};