#ifndef COMMAND_H
#define COMMAND_H

#include "Position.h"

enum CommandEnum
{
    ACTIVATE,
    COLLECT,
    EXECUTE,
    MOVE,
    ELIMINATE,
    REPORT,
    RETURN,
};

class Command
{
    public:
        Command(std::string commandString);

    private:
        CommandEnum command;
        int robotNumber;
        Position position;
        bool isPriority;

    friend class Base;
    friend class Robot;
};

#endif