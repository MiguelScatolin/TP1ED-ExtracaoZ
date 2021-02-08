#include "Command.h"
#include <string>
#include <sstream>

Command::Command(std::string commandString) {
    std::istringstream iss (commandString);
    if(iss.peek() == '*') {
        isPriority = true;
        iss.ignore(1);
    }

    std::string instruction;
    iss >> instruction;

    if(instruction == "MOVER")
        command = MOVE;
    else if(instruction == "COLETAR")
        command = COLLECT;
    else if(instruction == "ELIMINAR")
        command = ELIMINATE;
    else if(instruction == "ATIVAR")
        command = ACTIVATE;
    else if(instruction == "EXECUTAR")
        command = EXECUTE;
    else if(instruction == "RELATORIO")
        command = REPORT;
    else if(instruction == "RETORNAR")
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