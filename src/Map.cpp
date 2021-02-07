#include <iostream>
#include <fstream>
#include "Map.h"
using namespace std;

Map::Map(ifstream &mapFile) {

  mapFile >> xSize;
  mapFile >> ySize;

  map = new char*[xSize];

  for (int k = 0; k < xSize; k++)
    map[k] = new char[ySize];

  for (int i = 0; i < xSize; i++) {
    for (int j = 0; j < ySize; j++) {
      mapFile >> map[i][j];
    }
  }

  Print();
}

Map::~Map() {
  for (int i = 0; i < xSize; i++)
    free(map[i]);

  free(map);
}

void Map::Print() {
  for (int i = 0; i < xSize; i++) {
    for (int j = 0; j < ySize; j++) {
      cout << " " << map[i][j];
    }
    cout << endl;
  }
}

void Map::SetMapPositionValue(Position position, char newContent) {
  map[position.x][position.y] = newContent;
}

bool Map::CheckPositionForObstacle(Position position) {
  return map[position.x][position.y] == 'O';
}