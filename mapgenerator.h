#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

enum class Dir
{
	Entry_Up,
	Entry_Down,
	Entry_Left,
	Entry_Right
};

struct MazeFragment
{
	std::vector<std::vector<char>> mFragment;
	MazeFragment()
	{
		mFragment.resize(3);
		for (int i = 0; i < mFragment.size(); ++i)
		{
			mFragment[i].resize(mFragment.size());
			for (int j = 0; j < mFragment[i].size(); ++j)
			{
				mFragment[i][j] = '#';
			}
		}
	}
};

class MapGenerator{

	std::vector<MazeFragment> mAllFragments;
	std::unordered_map<Dir, std::vector<MazeFragment*>> mDirectionalFragments;
    std::vector<std::vector<char>> mazeMap;
	std::vector<std::vector<bool>> mIsVisited;

    void InitializeGenerator();
    int getRandomDirection(int access);
    void properlyGeneratorMap(int x, int y, int oldx, int oldy);//backup/obsolete
	void SetUpFragments();
	void ReadFragments();
	void InsertFragment(int x, int y, MazeFragment* lFragment);
	void FillEdge();
	void ProperlyGenerateMap(int x, int y, Dir lDir);
public:

    MapGenerator();

    int mapSizeX; 
    int mapSizeY;
    int travelDistance;

    std::vector<std::vector<char>> generateMap();
	std::pair<int, int>findFarthesPoint(int x, int y, int index);

};