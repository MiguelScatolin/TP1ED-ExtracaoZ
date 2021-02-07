#ifndef ROBOT_H
#define ROBOT_H

#include "Command.h"
#include "Position.h"
#include "Queue.h"
#include "Map.h"

class Robot
{
    public:
        Robot(int number, const Map &map);
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
        Queue<std::string> commandHistory;
        Map *map;

        void CollectResource();
        void Move(Position newPosition);
        void EliminateAlien();

    friend class Base;
};

#endif