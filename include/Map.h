#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

class Map
{
  public:
    Map(ifstream mapFile);
    ~Map();
    void Print();
    void SetMapPositionValue(int i, int j, char newContent);
    bool CheckPositionForObstacle(int i, int j);

  private:
    int xSize;
    int ySize;
    char **map;
};

#endif