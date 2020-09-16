#pragma once
#include <vector>
#include "Tile.h"

struct Player
{
	int x, y;
	char character = 'P';
	int color;
};

class Game;
class Map
{
	int mMapHeight;
	int mMapWidth;
	std::vector<std::vector<Tile>> mMap;
	int mEndTileX;
	int mEndTileY;
	Player mPlayer;
	//generator map dodac
	Game* mGame;
public:
	Map(Game* lGame);
	~Map();

	void GenerateMap();
	std::vector<std::vector<Tile>> GetMap();

	void GoUp();
	void GoDown();
	void GoRight();
	void GoLeft();

	void Update();
};