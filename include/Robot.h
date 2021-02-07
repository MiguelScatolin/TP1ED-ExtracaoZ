#ifndef ROBOT_H
#define ROBOT_H

#include "Position.h"
#include "Queue.h"

class Robot
{
    public:
        Robot();
        ~Robot();
        void CollectResource();
        void Move(Position newPosition);
        void Eliminate();
        void Report();
        void Return();
        void ExecuteCommands();

    private:
        int resources;
        int aliens;
        Position position;
        Queue<Command> commands;
};

#endif