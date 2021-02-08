#include "Command.h"
#include <string>
#include <sstream>

Command::Command(std::string commandString) {
    std::istringstream iss (commandString);
    if(iss.peek() == '*') {
        isPriority = true;
        iss.ignore(1);
    }

    std::string commandString;
    iss >> commandString;

    if(commandString == "MOVER")
        command = MOVE;
    else if(commandString == "COLETAR")
        command = COLLECT;
    else if(commandString == "ELIMINAR")
        command = ELIMINATE;
    else if(commandString == "ATIVAR")
        command = ACTIVATE;
    else if(commandString == "EXECUTAR")
        command = EXECUTE;
    else if(commandString == "RELATORIO")
        command = REPORT;
    else if(commandString == "RETORNAR")
        command = RETURN;
    else
        throw "Comando não reconhecido";

    iss >> robotNumber;

    char c = iss.peek();
    int x,y;
    while(c != EOF) {
        if(c == '(') {
            iss.ignore(1);
            iss >> x;
            iss.ignore(1);
            iss >> y;
            position = Position(x, y);
        }
        iss.ignore(1);
    }

};