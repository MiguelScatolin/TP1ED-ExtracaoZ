#ifndef BASE_H
#define BASE_H

#include <fstream>
#include "Robot.h"
#include "Command.h"
#include "Map.h"

class Base
{
    public:
        Base(std::ifstream &commandFile);
        ~Base();
        void FinalReport();
        void ExecuteCommands(const Map &map);

    private:
        int resources;
        int aliens;
        Robot *robots[50];
        Queue<Command> commands;

        void ActivateRobot(int robotNumber, const Map &map);
        void ReturnRobot(int robotNumber);
};

#endif