#include "mapgenerator.h"
#include <time.h>
#include <cstdlib>

MapGenerator::MapGenerator(){
    mapSizeY = 34;
    mapSizeX = 95;
    travelDistance = 3;
    srand(time(NULL));
}

void MapGenerator::initializeVector(){
    mazeMap.resize(mapSizeY);
    for(int i = 0; i < mapSizeY; i++){
        mazeMap[i].resize(mapSizeX);
        for (int j = 0; j < mapSizeX; j++){
            mazeMap[i][j] = '#';
        }
        
    }
}

void MapGenerator::properlyGeneratorMap(int x, int y){
    if(x < 0 || x >= mapSizeX || y < 0 || y >= mapSizeY){
        return;
    }
    mazeMap[y][x] = ' ';
    int direction = getRandomDirection(4);
    switch(direction){
        case 0:
			for (int i = 1; i < travelDistance; ++i)
			{
				if (x < 0 || x >= mapSizeX || y-i < 0 || y-i >= mapSizeY) {
					break;
				}
				mazeMap[y-i][x] = ' ';
			}
            properlyGeneratorMap(x, y-travelDistance);
        break;

        case 1:
			for (int i = 1; i < travelDistance; ++i)
			{
				if (x+i < 0 || x+i >= mapSizeX || y < 0 || y >= mapSizeY) {
					break;
				}
				mazeMap[y][x+i] = ' ';
			}
            properlyGeneratorMap(x+travelDistance, y);
        break;

        case 2:
			for (int i = 1; i < travelDistance; ++i)
			{
				if (x < 0 || x >= mapSizeX || y+i < 0 || y+i >= mapSizeY) {
					break;
				}
				mazeMap[y + i][x] = ' ';
			}
            properlyGeneratorMap(x, y+travelDistance);
        break;

        case 3:
			for (int i = 1; i < travelDistance; ++i)
			{
				if (x-i < 0 || x-i >= mapSizeX || y < 0 || y >= mapSizeY) {
					break;
				}
				mazeMap[y][x-i] = ' ';
			}
            properlyGeneratorMap(x-travelDistance, y);
        break;
    }
}

int MapGenerator::getRandomDirection(int access){
    int randomNumber = rand() % access;

    return randomNumber;
}

std::vector<std::vector<char>> MapGenerator::generateMap(){
    initializeVector();
    properlyGeneratorMap(mapSizeX/2, mapSizeY/2);
    return mazeMap;
}

