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
}

Map::~Map() {
  for (int i = 0; i < xSize; i++)
    delete[] map[i];

  delete[] map;
}

void Map::Print() {
  for (int i = 0; i < xSize; i++) {
    for (int j = 0; j < ySize; j++) {
      cout << " " << map[i][j];
    }
    cout << endl;
  }
}

bool Map::CheckPosition(Position position, char newContent) {
  return map[position.x][position.y] == newContent;
}

void Map::SetPosition(Position position, char newContent) {
  map[position.x][position.y] = newContent;
}

bool Map::CheckForObstacle(Position position) {
  return CheckPosition(position, 'O');
}

bool Map::EliminateAlien(Position position) {
  if(!CheckPosition(position, 'H'))
    return false;

  SetPosition(position, '.');
  return true;
}

bool Map::CollectResource(Position position) {
  if(!CheckPosition(position, 'R'))
    return false;

  SetPosition(position, '.');
  return true;
}