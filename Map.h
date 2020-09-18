#pragma once
#include <vector>
#include <cmath>
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
	float DistanceBetweenPoints(int x1, int y1, int x2, int y2);
	void InitializeMap(int x, int y);
	void GenerateMap();
	void ApplyViewRadius(std::vector<std::vector<Tile>>& lMap);

	std::vector<std::vector<Tile>> mMap;
	int mEndTileX;
	int mEndTileY;
	const int mViewRadius;
	bool mShowWholeMap;

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
	void ToggleViewDistance();

	void OnActivate();
	void OnDeactivate();
	void Update();
};