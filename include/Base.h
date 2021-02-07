#ifndef BASE_H
#define BASE_H

#include <fstream>
#include "Robot.h"
#include "Command.h"

class Base
{
    public:
        Base(std::ifstream &commandFile);
        void ActivateRobot(int robotNumber);
        void ReturnRobot(int robotNumber);
        void FinalReport();

    private:
        int resources;
        int aliens;
        Robot *position[50];
        Queue<Command> commands;
};

#endif