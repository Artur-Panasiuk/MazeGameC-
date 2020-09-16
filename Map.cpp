#include "Map.h"
#include "Game.h"

Map::Map(Game* lGame)
	:mGame(lGame)
{
}

Map::~Map()
{
}

void Map::GenerateMap()
{
}

std::vector<std::vector<Tile>> Map::GetMap()
{
	return mMap;
}

void Map::GoUp()
{
	if (mPlayer.y > 0)
	{
		if (mMap[mPlayer.y - 1][mPlayer.x].character != '#')
		{
			--mPlayer.y;
		}
	}
}

void Map::GoDown()
{
	if (mPlayer.y < mMap.size() - 1)
	{
		if (mMap[mPlayer.y + 1][mPlayer.x].character != '#')
		{
			++mPlayer.y;
		}
	}
}

void Map::GoRight()
{
	if (mPlayer.x < mMap[mPlayer.y].size() - 1)
	{
		if (mMap[mPlayer.y][mPlayer.x + 1].character != '#')
		{
			++mPlayer.x;
		}
	}
}

void Map::GoLeft()
{
	if (mPlayer.x > 0)
	{
		if (mMap[mPlayer.y][mPlayer.x - 1].character != '#')
		{
			--mPlayer.x;
		}
	}
}

void Map::Update()
{
	if (mPlayer.x == mEndTileX && mPlayer.y == mEndTileY)
	{
		mGame->mStateManager.SetState(State::GameOver);
	}
}
