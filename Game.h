#pragma once
#include "OutputManager.h"
#include "InputManager.h"
#include "StateManager.h"

class Game
{
	bool mIsOpen;
public:
	Game();
	~Game();

	bool IsOpen();
	void WriteOutput();
	void HandleInput();
	void Update();

	StateManager mStateManager;
	InputManager mInputManager;
	OutputManager mOutputManager;
};