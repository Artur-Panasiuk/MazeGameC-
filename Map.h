#pragma once
#include <vector>
#include "Tile.h"
#include "BaseState.h"

struct Player
{
	int x, y;
	char character;
	int color;
	Player(): x(10), y(10), character('P'), color(14){}
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
	//generator map dodac
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