#pragma once
#include <vector>

class MapGenerator{

    std::vector<std::vector<char>> mazeMap;

    void initializeVector();
    int getRandomDirection(int access);
    void properlyGeneratorMap(int x, int y);

public:

    MapGenerator();

    int mapSizeX; 
    int mapSizeY;
    int travelDistance;

    std::vector<std::vector<char>> generateMap();

};