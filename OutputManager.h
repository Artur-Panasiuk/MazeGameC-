#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include "Tile.h"

class Game;
class OutputManager
{
	void SetCursor(int x, int y);
	void SetColor(int lColor);
	void WriteGameMap();
	void ResizeWindow();

	int mDefaultColor = 15;
	std::vector<std::vector<Tile>> mOldDraw;
	HWND mConsole;
	Game *mGame;
public:
	OutputManager(Game *lGame);
	~OutputManager();

	void WriteOutput(); 
	void WriteError(std::string lErrorText);
	void ResetOldDraw();
};