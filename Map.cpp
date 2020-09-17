#include "Map.h"
#include "Game.h"

Map::Map(Game* lGame)
	:mGame(lGame), mViewRadius(6)
{
	mGame->mStateManager.AddState(State::Game, this);
}

Map::~Map()
{
}

float Map::DistanceBetweenPoints(int x1, int y1, int x2, int y2)
{
	return sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
}

void Map::InitializeMap(int x, int y)
{
	mMap.resize(y);
	for (int i = 0; i < y; ++i)
	{
		mMap[i].resize(x);
		for (int j = 0; j < x; ++j)
		{
			mMap[i][j].character = '.';
			mMap[i][j].color = 0;//czarny
		}
	}
}

void Map::GenerateMap()
{
	 std::vector<std::vector<char>> localMap = mMapGenerator.generateMap();
	 InitializeMap(localMap[0].size(), localMap.size());
	 for(int i = 0; i < localMap.size() ; i++){
		 for(int j = 0; j < localMap[0].size(); j++){
			 mMap[i][j].character = localMap[i][j];
		 }
	 }
}

void Map::ApplyViewRadius(std::vector<std::vector<Tile>>& lMap)
{
	for (int i = 0; i < lMap.size(); ++i)
	{
		for (int j = 0; j < lMap[0].size(); ++j)
		{
			if (DistanceBetweenPoints(mPlayer.x, mPlayer.y, j, i) < mViewRadius)
			{
				lMap[i][j].color = 15;
			}
		}
	}
}

std::vector<std::vector<Tile>> Map::GetMap()
{
	std::vector<std::vector<Tile>> map;
	map = mMap;
	ApplyViewRadius(map);
	map[mPlayer.y][mPlayer.x].character = mPlayer.character;
	map[mPlayer.y][mPlayer.x].color = mPlayer.color;
	return map;
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

void Map::OnActivate()
{
	GenerateMap();
	mPlayer.x = mMap[0].size() / 2;
	mPlayer.y = mMap.size() / 2;
	mGame->mOutputManager.ResetOldDraw();
}

void Map::OnDeactivate()
{
}

void Map::Update()
{
	if (mPlayer.x == mEndTileX && mPlayer.y == mEndTileY)
	{
		mGame->mStateManager.SetState(State::GameOver);
	}
}
