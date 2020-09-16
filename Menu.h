#pragma once
#include <string>

class Game;
class Menu
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
};