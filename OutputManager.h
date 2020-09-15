#pragma once
#include <iostream>
#include <string>

class Game;
class OutputManager
{
	void WriteGameMap();

	Game *mGame;
public:
	OutputManager(Game *lGame);
	~OutputManager();

	void WriteOutput(); 
	void WriteError(std::string lErrorText);
};