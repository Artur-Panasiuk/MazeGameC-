#pragma once

class Game;
class InputManager
{
	Game *mGame;
	char mInput;
public:
	InputManager(Game *lGame);
	~InputManager();

	void HandleInput();
};