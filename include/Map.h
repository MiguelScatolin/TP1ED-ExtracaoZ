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
    bool CheckForObstacle(Position position);
    bool EliminateAlien(Position position);
    bool CollectResource(Position position);

  private:
    int xSize;
    int ySize;
    char **map;
    void SetPosition(Position position, char newContent);
    bool CheckPosition(Position position, char newContent);
};

#endif