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
        commands.EnQueue(command);
}

void Robot::ExecuteCommands() {
    while(!priorityCommands.IsEmpty()) {
        ExecuteCommand(priorityCommands.Pop());
    }
    while(!commands.IsEmpty()) {
        ExecuteCommand(commands.DeQueue());
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

void Robot::AddCommandHistory(std::string newCommandHistory) {
    commandHistory.EnQueue("ROBO " + number + ' ' + newCommandHistory);
}

void Robot::CollectResource() {
    std::string positionString = position.ToString();
    if(currentMap->CollectResource(position)) {
        resources++;
        AddCommandHistory("RECURSOS COLETADOS EM " + positionString);
    }
    else
        AddCommandHistory("IMPOSSIVEL COLETAR RECURSOS EM " + positionString);
}

void Robot::Move(Position newPosition) {
    std::string positionString = position.ToString();
    if(!currentMap->CheckForObstacle(newPosition)) {
        position = newPosition;
        AddCommandHistory("MOVEU PARA " + positionString);
    }
    else
        AddCommandHistory("IMPOSSIVEL MOVER PARA " + positionString);
}


void Robot::EliminateAlien() {
    std::string positionString = position.ToString();
    if(currentMap->EliminateAlien(position)) {
        resources++;
        AddCommandHistory("ALIEN ELIMINADO EM " + positionString);
    }
    else
        AddCommandHistory("IMPOSSIVEL ELIMINAR ALIEN EM " + positionString);
}

void Robot::Report() {
    while(!commandHistory.IsEmpty()) {
        std::cout << commandHistory.DeQueue() << std::endl;
    }
}