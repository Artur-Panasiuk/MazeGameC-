#include "Menu.h"
#include "Game.h"

Menu::Menu(Game* lGame)
	: mGame(lGame), mOption(0), mOptionMax(1)
{
	mGame->mStateManager.AddState(State::Menu, this);
}

Menu::~Menu()
{
}

std::string Menu::GetString()
{
	std::string output = "";
	output += "\n\n";

	output += "\t Przed toba jest labirynt z ktorego musisz znalezc wyjscie\n";
	output += "\t oznaczone znakiem '@' . Poruszasz sie WASD. Opcje zatwierdzasz ENTERem.\n\n";

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

void Menu::OnActivate()
{
}

void Menu::OnDeactivate()
{
}
