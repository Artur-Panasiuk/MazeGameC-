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

void MapGenerator::properlyGeneratorMap(int x, int y, int oldx, int oldy){
	if (x <= 0 || x >= mapSizeX - 1 || y <= 0 || y >= mapSizeY - 1) {
        return;
    }
	if (oldx > x)//droga od prawej
	{
		if (mazeMap[y - 1][x] != '#' || mazeMap[y + 1][x] != '#' || mazeMap[y][x - 1] != '#')
		{
			std::cout << "end1" << std::endl;
			system("pause");
			return;
		}
	}
	else if (oldx < x)//droga od lewej
	{
		if (mazeMap[y - 1][x] != '#' || mazeMap[y + 1][x] != '#' || mazeMap[y][x + 1] != '#')
		{
			std::cout << "end2" << std::endl;
			system("pause");
			return;;
		}
	}
	else if (oldy < y)//droga od gory
	{
		if (mazeMap[y][x + 1] != '#' || mazeMap[y + 1][x] != '#' || mazeMap[y][x - 1] != '#')
		{
			std::cout << "end3" << std::endl;
			system("pause");
			return;;
		}
	}
	else//droga od dolu
	{
		if (mazeMap[y - 1][x] != '#' || mazeMap[y][x + 1] != '#' || mazeMap[y][x - 1] != '#')
		{
			std::cout << "end4" << std::endl;
			system("pause");
			return;;
		}
	}


    mazeMap[y][x] = ' ';
	std::cout << "-----------------------\n";
	system("pause");
	int random = rand() % 10;
	std::cout << random << std::endl;
	if (random < 6)//korytarz
	{
		mazeMap[y][x] = 'K';
		random = 2 + rand() % travelDistance;
		std::cout << random << std::endl;
		if (oldx > x)//droga w lewo
		{
			if (x - random < 0)
				return;

			for (int i = 1; i < random; ++i)
			{
				mazeMap[y][x - i] = ' ';
			}
			properlyGeneratorMap(x - random, y, x, y);
		}
		else if (oldx < x)//droga w prawo
		{
			if (x + random >= mazeMap[0].size())
				return;

			for (int i = 1; i < random; ++i)
			{
				mazeMap[y][x + i] = ' ';
			}
			properlyGeneratorMap(x + random, y, x, y);
		}
		else if (oldy < y)//droga w dol
		{
			if (y + random >= mazeMap.size())
				return;

			for (int i = 1; i < random; ++i)
			{
				mazeMap[y + i][x] = ' ';
			}
			properlyGeneratorMap(x, y+random, x, y);
		}
		else//droga w gore
		{
			if (y - random < 0)
				return;

			for (int i = 1; i < random; ++i)
			{
				mazeMap[y - i][x] = ' ';
			}
			properlyGeneratorMap(x, y - random, x, y);
		}
	}
	else if (random > 6)//skret
	{
		mazeMap[y][x] = 'S';
		random = rand() % 2;
		std::cout << random << std::endl;
		if (random == 1)//skret w prawo
		{
			if (oldx > x)//droga od prawej
			{
				if (y - 1 < 0)
					return;
				properlyGeneratorMap(x, y-1, x, y);
			}
			else if (oldx < x)//droga od lewej
			{
				if (y+1 >= mazeMap.size())
					return;
				properlyGeneratorMap(x, y+1, x, y);
			}
			else if (oldy < y)//droga od gory
			{
				if (x-1 < 0)
					return;
				properlyGeneratorMap(x-1, y, x, y);
			}
			else//droga od dolu
			{
				if (x+1 >= mazeMap[0].size())
					return;
				properlyGeneratorMap(x+1, y, x, y);
			}
		}
		else//skret w lewo
		{
			if (oldx > x)//droga od prawej
			{
				if (y + 1 >= mazeMap.size())
					return;
				properlyGeneratorMap(x, y + 1, x, y);
			}
			else if (oldx < x)//droga od lewej
			{
				if (y - 1 < 0)
					return;
				properlyGeneratorMap(x, y - 1, x, y);
			}
			else if (oldy < y)//droga od gory
			{
				if (x + 1 >= mazeMap[0].size())
					return;
				properlyGeneratorMap(x + 1, y, x, y);
			}
			else//droga od dolu
			{
				if (x - 1 < 0)
					return;
				properlyGeneratorMap(x - 1, y, x, y);
			}
		}
	}
	else//skrzy¿owanie
	{
	mazeMap[y][x] = 'X';
		random = rand() % 4;
		std::cout << random << std::endl;
		if (random == 0)//skrzyzowanie lewo-przod
		{
			if (oldx > x)//droga od prawej
			{
				if (y + 1 >= mazeMap.size() || x - 1 < 0)
					return;
				properlyGeneratorMap(x, y + 1, x, y);
				properlyGeneratorMap(x - 1, y, x, y);
			}
			else if (oldx < x)//droga od lewej
			{
				if (y - 1 < 0 || x + 1 >= mazeMap[0].size())
					return;
				properlyGeneratorMap(x, y - 1, x, y);
				properlyGeneratorMap(x + 1, y, x, y);
			}
			else if (oldy < y)//droga od gory
			{
				if (x + 1 >= mazeMap[0].size() || y + 1 >= mazeMap.size())
					return;
				properlyGeneratorMap(x + 1, y, x, y);
				properlyGeneratorMap(x, y + 1, x, y);
			}
			else//droga od dolu
			{
				if (x - 1 < 0 || y - 1 < 0)
					return;
				properlyGeneratorMap(x - 1, y, x, y);
				properlyGeneratorMap(x, y - 1, x, y);
			}
		}
		else if (random == 1)//skrzyzowanie prawo-przod
		{
			if (oldx > x)//droga od prawej
			{
				if (y - 1 < 0 || x - 1 < 0)
					return;
				properlyGeneratorMap(x, y - 1, x, y);
				properlyGeneratorMap(x - 1, y, x, y);
			}
			else if (oldx < x)//droga od lewej
			{
				if (y + 1 >= mazeMap.size() || x + 1 >= mazeMap[0].size())
					return;
				properlyGeneratorMap(x, y + 1, x, y);
				properlyGeneratorMap(x + 1, y, x, y);
			}
			else if (oldy < y)//droga od gory
			{
				if (x - 1 < 0 || y + 1 >= mazeMap.size())
					return;
				properlyGeneratorMap(x - 1, y, x, y);
				properlyGeneratorMap(x, y + 1, x, y);
			}
			else//droga od dolu
			{
				if (x + 1 >= mazeMap[0].size() || y - 1 < 0)
					return;
				properlyGeneratorMap(x + 1, y, x, y);
				properlyGeneratorMap(x, y - 1, x, y);
			}
		}
		else if(random == 2)//skrzyzowanie lewo-prawo
		{
			if (oldx > x)//droga od prawej
			{
				if (y - 1 < 0 || y + 1 >= mazeMap.size())
					return;
				properlyGeneratorMap(x, y - 1, x, y);
				properlyGeneratorMap(x, y + 1, x, y);
			}
			else if (oldx < x)//droga od lewej
			{
				if (y - 1 < 0 || y + 1 >= mazeMap.size())
					return;
				properlyGeneratorMap(x, y - 1, x, y);
				properlyGeneratorMap(x, y + 1, x, y);
			}
			else if (oldy < y)//droga od gory
			{
				if (x - 1 < 0 || x + 1 >= mazeMap[0].size())
					return;
				properlyGeneratorMap(x - 1, y, x, y);
				properlyGeneratorMap(x + 1, y, x, y);
			}
			else//droga od dolu
			{
				if (x - 1 < 0 || x + 1 >= mazeMap[0].size())
					return;
				properlyGeneratorMap(x - 1, y, x, y);
				properlyGeneratorMap(x + 1, y, x, y);
			}
		}
		else//skrzyzowanie lewo-prawo-przod
		{
			if (oldx > x)//droga od prawej
			{
				if (y - 1 < 0 || y + 1 >= mazeMap.size() || x - 1 < 0)
					return;
				properlyGeneratorMap(x, y - 1, x, y);
				properlyGeneratorMap(x, y + 1, x, y);
				properlyGeneratorMap(x - 1, y, x, y);
			}
			else if (oldx < x)//droga od lewej
			{
				if (y - 1 < 0 || y + 1 >= mazeMap.size() || x + 1 >= mazeMap[0].size())
					return;
				properlyGeneratorMap(x, y - 1, x, y);
				properlyGeneratorMap(x, y + 1, x, y);
				properlyGeneratorMap(x + 1, y, x, y);
			}
			else if (oldy < y)//droga od gory
			{
				if (x - 1 < 0 || x + 1 >= mazeMap[0].size() || y + 1 >= mazeMap.size())
					return;
				properlyGeneratorMap(x - 1, y, x, y);
				properlyGeneratorMap(x + 1, y, x, y);
				properlyGeneratorMap(x , y + 1, x, y);
			}
			else//droga od dolu
			{
				if (x - 1 < 0 || x + 1 >= mazeMap[0].size() || y - 1 < 0)
					return;
				properlyGeneratorMap(x - 1, y, x, y);
				properlyGeneratorMap(x + 1, y, x, y);
				properlyGeneratorMap(x, y - 1, x, y);
			}
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

