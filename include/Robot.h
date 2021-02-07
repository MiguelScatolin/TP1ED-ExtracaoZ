#ifndef ROBOT_H
#define ROBOT_H

#include "Position.h"
#include "Queue.h"
#include "Map.h"

class Robot
{
    public:
        Robot();
        ~Robot();
        void ExecuteCommands(Map map);
        void Return();

    private:
        int resources;
        int aliens;
        Position position;
        Queue<Command> commands;

        void CollectResource();
        void Move(Position newPosition);
        void Eliminate();
        void Report();
};

#endif