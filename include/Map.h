#ifndef MAP_H
#define MAP_H

#include <fstream>
#include "Position.h"

class Map
{
  public:
    Map(std::ifstream &mapFile);
    ~Map();
    void Print();
    void SetMapPositionValue(Position position, char newContent);
    bool CheckPositionForObstacle(Position position);
    bool EliminateAlien(Position position);
    bool CollectResource(Position position);

  private:
    int xSize;
    int ySize;
    char **map;
};

#endif