#include "Robot.h"
#include <iostream>
#include "Map.h"

Robot::Robot(int robotNumber, Map *map) {
    resources = 0;
    number = robotNumber;
    aliens = 0;
    position = Position(0, 0);
    currentMap = map;
}

void Robot::AddCommand(Command command) {
    if(command.isPriority)
        priorityCommands.Push(command);
    else
        commands.Push(command);
}

void Robot::ExecuteCommands() {
    while(!priorityCommands.IsEmpty()) {
        Command command = commands.Pop();
    }
    while(!commands.IsEmpty()) {
        Command command = commands.Pop();
    }
};

void Robot::ExecuteCommand(Command command) {
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

void Robot::CollectResource() {
    if(currentMap->CollectResource(position)) {
        resources++;
        commandHistory.Push("RECURSOS COLETADOS EM (i,j)");
    }
    commandHistory.Push("ROBO k: IMPOSSIVEL COLETAR RECURSOS EM (i,j)");
}

void Robot::Move(Position newPosition) {
    if(!currentMap->CheckPositionForObstacle(newPosition)) {
        position = newPosition;
        commandHistory.Push("ROBO k: MOVEU PARA (i,j)");
    }
    commandHistory.Push("ROBO k: IMPOSSIVEL MOVER PARA (i,j)");
}


void Robot::EliminateAlien() {
    if(currentMap->EliminateAlien(position)) {
        resources++;
        commandHistory.Push("ROBO k: ALIEN ELIMINADO EM (i,j)");
    }
    commandHistory.Push("ROBO k: IMPOSSIVEL ELIMINAR ALIEN EM (i,j)");
}

void Robot::Report() {
    while(!commandHistory.IsEmpty()) {
        std::cout << commandHistory.Pop() << std::endl;
    }
}