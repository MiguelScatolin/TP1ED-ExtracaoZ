#ifndef ROBOT_H
#define ROBOT_H

#include "Command.h"
#include "Position.h"
#include "Queue.h"
#include "Stack.h"
#include "Map.h"

class Robot
{
    public:
        Robot(int robotNumber, Map *currentMap);
        ~Robot();
        void AddCommand(Command command);
        void ExecuteCommands();
        void Report();

    private:
        int resources;
        int number;
        int aliens;
        Position position;
        Queue<Command> commands;
        Stack<Command> priorityCommands;
        Queue<std::string> commandHistory;
        Map *currentMap;

        void CollectResource();
        void Move(Position newPosition);
        void EliminateAlien();
        void ExecuteCommand(Command command);

    friend class Base;
};

#endif