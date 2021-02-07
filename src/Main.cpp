#include <iostream>
#include <fstream>
#include <string>
#include "Map.h"
#include "Base.h"

int main(int argc, char* argv[]) {
  if(argc < 3)
    throw "Nome do arquivo de mapa ou de comandos não informado.";

  ifstream mapFile(argv[1]);
  ifstream commandFile(argv[2]);

  if (mapFile.is_open())
    throw  "Erro ao abrir arquivo de mapa";
  if (commandFile.is_open())
    throw  "Erro ao abrir arquivo de comandos";

  Map map(mapFile);
  Base base(commandFile);

  base.ExecuteCommands();

  base.FinalReport();

  return 0;
}