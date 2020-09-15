#include "OutputManager.h"
#include "Game.h"

void OutputManager::WriteGameMap()
{
	//to do
}

OutputManager::OutputManager(Game *lGame)
	: mGame(lGame)
{
}

OutputManager::~OutputManager()
{
}

void OutputManager::WriteOutput()
{
	if (mGame->mStateManager.GetState() == State::Game)
	{
		WriteGameMap();
	}
	else if (mGame->mStateManager.GetState() == State::Menu)
	{
		system("cls");
		std::cout << mGame->mMenu.GetMenuString();
	}
}

void OutputManager::WriteError(std::string lErrorText)
{
	system("cls");
	std::cout << "Error: " << lErrorText << "\n";
	system("pause");
}
