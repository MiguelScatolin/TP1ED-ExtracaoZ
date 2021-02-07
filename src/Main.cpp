#include <iostream>
#include <fstream>
#include <string>
#include "Map.h"
#include "Base.h"

int main(int argc, char* argv[]) {
  if(argc < 3)
    throw "Nome do arquivo de mapa ou de comandos não informado.";

  std::ifstream mapFile(argv[1]);
  std::ifstream commandFile(argv[2]);

  if (mapFile.is_open())
    throw  "Erro ao abrir arquivo de mapa";
  if (commandFile.is_open())
    throw  "Erro ao abrir arquivo de comandos";

  Map map(mapFile);
  Base base(commandFile);

  base.ExecuteCommands(map);

  base.FinalReport();

  return 0;
}