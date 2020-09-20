#include "OutputManager.h"
#include "Game.h"

void OutputManager::SetCursor(int x, int y)
{
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void OutputManager::SetColor(int lColor)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, lColor);
}

void OutputManager::WriteGameMap()
{
	auto map = mGame->mMap.GetMap();
	if (mOldDraw.empty())
	{
		system("cls");
		for (int i = 0; i < map.size(); ++i)
		{
			for (int j = 0; j < map[0].size(); ++j)
			{
				SetColor(map[i][j].color);
				std::cout << map[i][j].character;
			}
			std::cout << std::endl;
		}
	}
	else
	{
		for (int i = 0; i < map.size(); ++i)
		{
			for (int j = 0; j < map[0].size(); ++j)
			{
				if (mOldDraw[i][j].character != map[i][j].character || mOldDraw[i][j].color != map[i][j].color)
				{
					SetCursor(j, i);
					SetColor(map[i][j].color);
					std::cout << map[i][j].character;
				}
			}
		}
		SetCursor(0, map.size());
	}
	SetColor(mDefaultColor);
	mOldDraw = map;
}

OutputManager::OutputManager(Game *lGame)
	: mGame(lGame)
{
	ResizeWindow();
}

OutputManager::~OutputManager()
{
}

void OutputManager::ResizeWindow()
{
	mConsole = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(mConsole, &ConsoleRect);
	MoveWindow(mConsole, ConsoleRect.left, ConsoleRect.top, 800, 600, TRUE);
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
		std::cout << mGame->mMenu.GetString();
	}
	else if (mGame->mStateManager.GetState() == State::GameOver)
	{
		system("cls");
		std::cout << mGame->mGameOver.GetString();
	}
}

void OutputManager::WriteError(std::string lErrorText)
{
	system("cls");
	std::cout << "Error: " << lErrorText << "\n";
	system("pause");
}

void OutputManager::ResetOldDraw()
{
	mOldDraw.clear();
}
