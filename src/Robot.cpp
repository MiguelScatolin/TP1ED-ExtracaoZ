#include "Robot.h"
#include "Map.h"


void Robot::ExecuteCommands() {
    while(!commands.IsEmpy()) {
        Command command = commands.Pop();

        switch (command.command) {
            case COLLECT:
                CollectResource();
                break;
            case MOVE:
                Move(command.position);
                break;
            case ELIMINATE:
                EliminateAlien();
                break;
            default:
                break;
        }
    }
};

void Robot::CollectResource() {
    if(map->CollectResource(position)) {
        resources++;
        commandHistory.Push("RECURSOS COLETADOS EM (i,j)");
    }
    commandHistory.Push("ROBO k: IMPOSSIVEL COLETAR RECURSOS EM (i,j)");
}

void Robot::Move(Position newPosition) {
    if(!map->CheckPositionForObstacle(newPosition)) {
        position = newPosition;
        commandHistory.Push("ROBO k: MOVEU PARA (i,j)");
    }
    commandHistory.Push("ROBO k: IMPOSSIVEL MOVER PARA (i,j)");
}


void Robot::EliminateAlien() {
    if(map->EliminateAlien(position)) {
        resources++;
        commandHistory.Push("ROBO k: ALIEN ELIMINADO EM (i,j)");
    }
    commandHistory.Push("ROBO k: IMPOSSIVEL ELIMINAR ALIEN EM (i,j)");
}