#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Test.hpp"
#include "Map.hpp"
using namespace std;

int main(int argc, char* argv[]) {
  if(argc < 2)
    throw "Nome do arquivo de mapa ou de comandos não informado.";

  ifstream mapFile(argv[0]);
  ifstream commandFile(argv[1]);

  if (mapFile.is_open())
    throw  "Erro ao abrir arquivo de mapa";
  if (commandFile.is_open())
    throw  "Erro ao abrir arquivo de comandos";

  Map map = new Map(mapFile);

  Test* pTest = new Test();
  pTest->Print();
  return 0;
}