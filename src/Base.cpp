#include <iostream>
#include "Base.h"
#include "Command.h"

#define BASE_STRING "BASE: "
#define ROBO_STRING "ROBO "

Base::Base(std::ifstream &commandFile) {
    resources = 0;
    aliens = 0;
    for(int i =0; i<50; i++)
        robots[i] = nullptr;
    std::string s;
    while(getline(commandFile, s)) {
        Command command(s);
        commands.EnQueue(command);
    }
};

void Base::ExecuteCommands(Map *map) {
    while(!commands.IsEmpty()) {
        Command command = commands.DeQueue();

       switch (command.command) {
            case ACTIVATE:
                ActivateRobot(command.robotNumber, map);
                break;
            case EXECUTE:
                robots[command.robotNumber]->ExecuteCommands();
                break;
            case RETURN:
                ReturnRobot(command.robotNumber);
                break;
            case REPORT:
                if(robots[command.robotNumber] != nullptr)
                    robots[command.robotNumber]->Report();
                break;
            default:
                if(robots[command.robotNumber] != nullptr)
                    robots[command.robotNumber]->AddCommand(command);
                break;
        }
    }
};

void Base::ActivateRobot(int robotNumber, Map *map) {
    if(robots[robotNumber] == nullptr) {
        robots[robotNumber] = new Robot(robotNumber, map);
        std::cout << BASE_STRING << ROBO_STRING << robotNumber << " SAIU EM MISSAO" << std::endl;
    }
    else
        std::cout << BASE_STRING << ROBO_STRING << robotNumber << " JA ESTA EM MISSAO" << std::endl;
};

void Base::ReturnRobot(int robotNumber) {
    if(robots[robotNumber] == nullptr) {
        std::cout << BASE_STRING << ROBO_STRING << robotNumber << " NAO ESTA EM MISSAO" << std::endl;
        return;
    }

    int returnedAliens = robots[robotNumber]->aliens;
    int returnedResources = robots[robotNumber]->resources;
    robots[robotNumber] = nullptr;

    std::cout << BASE_STRING << ROBO_STRING << robotNumber << " RETORNOU ALIENS " << returnedAliens << " RECURSOS " << returnedResources << std::endl;

    aliens += returnedAliens;
    resources += returnedResources;
};

void Base::FinalReport() {
    std::cout << BASE_STRING << "TOTAL DE ALIENS " << aliens << " RECURSOS " << resources << std::endl;
}