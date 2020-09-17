#pragma once
#include <vector>
#include "Tile.h"
#include "BaseState.h"
#include "mapgenerator.h"

struct Player
{
	int x, y;
	char character;
	int color;
	Player(): x(20), y(20), character('P'), color(10){}
};

class Game;
class Map : public BaseState
{
	void InitializeMap(int x, int y);
	void GenerateMap();

	std::vector<std::vector<Tile>> mMap;
	int mEndTileX;
	int mEndTileY;
	Player mPlayer;
	MapGenerator mMapGenerator;
	Game* mGame;
public:
	Map(Game* lGame);
	~Map();

	std::vector<std::vector<Tile>> GetMap();

	void GoUp();
	void GoDown();
	void GoRight();
	void GoLeft();

	void OnActivate();
	void OnDeactivate();
	void Update();
};