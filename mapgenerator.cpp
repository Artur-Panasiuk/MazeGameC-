#include "mapgenerator.h"
#include <time.h>
#include <cstdlib>

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

int MapGenerator::getRandomDirection(int access){
    int randomNumber = rand() % access;

    return randomNumber;
}

std::vector<std::vector<char>> MapGenerator::generateMap(){
    InitializeGenerator();
	ProperlyGenerateMap(mapSizeX / 2, mapSizeY / 2, Dir::Entry_Up);
	FillEdge();
    return mazeMap;
}

std::pair<int, int> MapGenerator::findFarthesPoint(int x, int y, int index){

	std::pair <int, int> FarthestPointOutput; //y, x

	for(int a = 0 + index; a <= x; a++){
		if(mazeMap[0][a] == ' '){
			FarthestPointOutput.first = 0;
			FarthestPointOutput.second = a;
			return FarthestPointOutput;
		}
	}
	for(int b = 0 + index; b <= y; b++){
		if(mazeMap[b][x] == ' '){
			FarthestPointOutput.first = b;
			FarthestPointOutput.second = x;
			return FarthestPointOutput;
		}
	}
	for(int c = x - index; c >= 0; c--){
		if(mazeMap[y][c] == ' '){
			FarthestPointOutput.first = y;
			FarthestPointOutput.second = c;
			return FarthestPointOutput;
		}
	}
	for(int d = y - index; d >= 0; d--){
		if(mazeMap[d][0] == ' '){
			FarthestPointOutput.first = d;
			FarthestPointOutput.second = 0;
			return FarthestPointOutput;
		}
	}
	return findFarthesPoint(x-1, y-1, index+1);
}

