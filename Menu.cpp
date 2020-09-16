#include "Menu.h"
#include "Game.h"

Menu::Menu(Game* lGame)
	: mGame(lGame), mOption(0), mOptionMax(1)
{
}

Menu::~Menu()
{
}

std::string Menu::GetString()
{
	std::string output = "";
	output += "\n\n";
	if (mOption == 0)
	{
		output += "\t> Graj <\n";
	}
	else
	{
		output += "\t  Graj  \n";
	}
	if (mOption == 1)
	{
		output += "\t> Wyjdz <\n";
	}
	else
	{
		output += "\t  Wyjdz  \n";
	}

	return output;
}

void Menu::MovePointerUp()
{
	if (mOption == 0)
		return;

	--mOption;
}

void Menu::MovePointerDown()
{
	if (mOption == mOptionMax)
		return;

	++mOption;
}

void Menu::Enter()
{
	if (mOption == 0)
	{
		mGame->mStateManager.SetState(State::Game);
	}
	else if (mOption == 1)
	{
		mGame->EndGame();
	}
}
