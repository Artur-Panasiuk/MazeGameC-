#include "GameOver.h"
#include "Game.h"

GameOver::GameOver(Game* lGame)
	: mGame(lGame), mOption(0), mMaxOption(1)
{
	mGame->mStateManager.AddState(State::GameOver, this);
}

GameOver::~GameOver()
{
}

std::string GameOver::GetString()
{
	std::string time = std::to_string(mGame->mMap.GetDiffTime());
	for (int i = 0; i < time.size(); ++i)
	{
		if (time[i] == '.')
		{
			time = time.substr(0, i + 3);
			break;
		}
	}

	std::string text = "";

	text += "\n\n\tGratulacje! Udalo ci sie wyjsc z labiryntu!\n";
	text += "\t Twoj czas to ";
	text +=  time + " minut\n";
	text +=	"\tWygenerowac nastepny poziom?\n\n";
	if (mOption == 0)
	{
		text += "\t\t>Generuj<\t Wyjdz \n";
	}
	else if (mOption == 1)
	{
		text += "\t\t Generuj \t>Wyjdz<\n";
	}
	return text;
}

void GameOver::MovePointerLeft()
{
	if (mOption == 0)
		return;

	--mOption;
}

void GameOver::MovePointerRight()
{
	if (mOption == mMaxOption)
		return;
	++mOption;
}

void GameOver::Enter()
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

void GameOver::OnActivate()
{
}

void GameOver::OnDeactivate()
{
}
