#include "mapgenerator.h"
#include <time.h>
#include <cstdlib>
#include <queue>

MapGenerator::MapGenerator(){
    mapSizeY = 33;
    mapSizeX = 93;
    travelDistance = 3;
    srand(time(NULL));
	ReadFragments();
	SetUpFragments();
}

void MapGenerator::InitializeGenerator(){
    mazeMap.resize(mapSizeY);
	mIsVisited.resize(mapSizeY);
    for(int i = 0; i < mapSizeY; i++){
        mazeMap[i].resize(mapSizeX);
		mIsVisited[i].resize(mapSizeX);
		for (int j = 0; j < mapSizeX; j++) {
			mazeMap[i][j] = '#';
			mIsVisited[i][j] = false;
		}
    }
}

void MapGenerator::SetUpFragments()
{
	std::vector<MazeFragment*> empty;
	mDirectionalFragments[Dir::Entry_Down] = empty;
	mDirectionalFragments[Dir::Entry_Up] = empty;
	mDirectionalFragments[Dir::Entry_Right] = empty;
	mDirectionalFragments[Dir::Entry_Left] = empty;
	for (int i = 0; i < mAllFragments.size(); ++i)
	{
		if (mAllFragments[i].mFragment[0][1] == ' ')
		{
			mDirectionalFragments[Dir::Entry_Up].push_back(&mAllFragments[i]);
		}
		if (mAllFragments[i].mFragment[2][1] == ' ')
		{
			mDirectionalFragments[Dir::Entry_Down].push_back(&mAllFragments[i]);
		}
		if (mAllFragments[i].mFragment[1][0] == ' ')
		{
			mDirectionalFragments[Dir::Entry_Left].push_back(&mAllFragments[i]);
		}
		if (mAllFragments[i].mFragment[1][2] == ' ')
		{
			mDirectionalFragments[Dir::Entry_Right].push_back(&mAllFragments[i]);
		}
	}
}

void MapGenerator::ReadFragments()
{
	MazeFragment newFragment;
	std::string line;
	std::ifstream file;
	file.open("maze.fr");

	if (file.is_open() == false)
	{
		std::cerr << "Error: Failed to open maze.fr" << std::endl;
		system("pause");
		return;
	}
	int i = 0;
	while (std::getline(file, line))
	{
		for (int j = 0; j < newFragment.mFragment[i % 3].size(); ++j)
		{
			newFragment.mFragment[i % 3][j] = line[j];
		}
		if (i % 3 == 2)
		{
			mAllFragments.push_back(newFragment);
		}
		++i;
	
	}
	file.close();
}

void MapGenerator::InsertFragment(int x, int y, MazeFragment * lFragment)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			mazeMap[y + i][x + j] = lFragment->mFragment[i][j];
		}
	}
}

void MapGenerator::FillEdge()
{
	for (int i = 0; i < mapSizeY; i++)
	{
		if (i == 0 || i == mapSizeY - 1)
		{
			for (int j = 0; j < mapSizeX; ++j)
			{
				mazeMap[i][j] = '#';
			}
		}
		else
		{
			mazeMap[i][0] = '#';
			mazeMap[i][mapSizeX - 1] = '#';
		}
	}
}

void MapGenerator::ProperlyGenerateMap(int x, int y, Dir lDir)
{
	if (x < 0 || x >= mapSizeX || y < 0 || y >= mapSizeY) 
		return;

	x = x / 3 * 3;
	y = y / 3 * 3;
	if (mIsVisited[y][x] == true)
		return;
	mIsVisited[y][x] = true;

	int random = rand() % 7;
	MazeFragment* chosenFragment = mDirectionalFragments[lDir][random];
	InsertFragment(x, y, chosenFragment);

	if (chosenFragment->mFragment[0][1] == ' ')
	{
		ProperlyGenerateMap(x, y - 3, Dir::Entry_Down);
	}
	if (chosenFragment->mFragment[2][1] == ' ')
	{
		ProperlyGenerateMap(x, y + 3, Dir::Entry_Up);
	}
	if (chosenFragment->mFragment[1][0] == ' ')
	{
		ProperlyGenerateMap(x - 3, y, Dir::Entry_Right);
	}
	if (chosenFragment->mFragment[1][2] == ' ')
	{
		ProperlyGenerateMap(x + 3, y, Dir::Entry_Left);
	}

}

std::vector<std::vector<char>> MapGenerator::generateMap(){
    InitializeGenerator();
	ProperlyGenerateMap(mapSizeX / 2, mapSizeY / 2, Dir::Entry_Up);
	FillEdge();
    return mazeMap;
}

std::pair<int, int> MapGenerator::findFarthesPoint(int x, int y){

	std::queue<std::pair<int, int>> que;

	que.push(std::make_pair(y, x));
	std::pair<int, int> currentCoordinates;

	std::vector<std::vector<bool>> isVisited;

	isVisited.resize(mazeMap.size());
	for(int i = 0; i < mazeMap.size(); i++){
		isVisited[i].resize(mazeMap[i].size());
		for(int j=0; j < mazeMap[0].size(); j++){
			isVisited[i][j] = false;
		}
	}

	
	while(!que.empty()){
		currentCoordinates = que.front();
		que.pop();
		isVisited[currentCoordinates.first][currentCoordinates.second] = true;
		if(currentCoordinates.first + 1 < mazeMap.size() && 
		isVisited[currentCoordinates.first + 1][currentCoordinates.second] == false && 
		mazeMap[currentCoordinates.first + 1][currentCoordinates.second] != '#'){
			que.push(std::make_pair(currentCoordinates.first + 1, currentCoordinates.second));
		}
		if(currentCoordinates.second + 1 < mazeMap[0].size() && 
		isVisited[currentCoordinates.first][currentCoordinates.second + 1] == false &&
		mazeMap[currentCoordinates.first][currentCoordinates.second + 1] != '#'){
			que.push(std::make_pair(currentCoordinates.first, currentCoordinates.second + 1));
		}
		if(currentCoordinates.first - 1 >= 0 && 
		isVisited[currentCoordinates.first - 1][currentCoordinates.second] == false &&
		mazeMap[currentCoordinates.first - 1][currentCoordinates.second] != '#'){
			que.push(std::make_pair(currentCoordinates.first - 1, currentCoordinates.second));
		}
		if(currentCoordinates.second - 1 >= 0 && 
		isVisited[currentCoordinates.first][currentCoordinates.second - 1] == false &&
		mazeMap[currentCoordinates.first][currentCoordinates.second - 1] != '#'){
			que.push(std::make_pair(currentCoordinates.first, currentCoordinates.second - 1));
		}
	}
	return currentCoordinates;
}

