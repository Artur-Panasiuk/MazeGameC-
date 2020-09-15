#include "OutputManager.h"

OutputManager::OutputManager(Game *lGame)
	: mGame(lGame)
{
}

OutputManager::~OutputManager()
{
}

void OutputManager::WriteOutput()
{
}

void OutputManager::WriteError(std::string lErrorText)
{
	system("cls");
	std::cout << "Error: " << lErrorText << "\n";
	system("pause");
}
