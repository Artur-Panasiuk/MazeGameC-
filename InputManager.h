#pragma once
#include <conio.h>

class Game;
class InputManager
{
	Game *mGame;
	char mInput;
	const int EnterCode = 13;
	
	void InputForMenu();
	void InputForGame();

public:
	InputManager(Game *lGame);
	~InputManager();

	void HandleInput();
};