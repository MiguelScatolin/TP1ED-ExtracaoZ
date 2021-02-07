#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include "Position.h"

class Command
{
    Command(std::string commandString);
    void Execute();

    private:
        std::string command;
        int robotNumber;
        Position position;
        bool isPriority;
};

#endif