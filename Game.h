#pragma once
#include "OutputManager.h"
#include "InputManager.h"
#include "StateManager.h"
#include "Menu.h"
#include "Map.h"

class Game
{
	bool mIsOpen;
public:
	Game();
	~Game();

	bool IsOpen();
	void EndGame();

	void WriteOutput();
	void HandleInput();
	void Update();

	StateManager mStateManager;
	InputManager mInputManager;
	OutputManager mOutputManager;
	Menu mMenu;
	Map mMap;
};