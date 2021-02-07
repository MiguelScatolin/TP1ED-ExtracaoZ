#include <iostream>
#include "Base.h"
#include "Command.h"

#define BASE_STRING "BASE: "
#define ROBO_STRING "ROBO "

Base::Base(std::ifstream &commandFile) {

};

Base::~Base() {
};

void Base::ExecuteCommands(const Map &map) {
    while(!commands.IsEmpy()) {
        Command command = commands.Pop();

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
                robots[command.robotNumber]->Report();
                break;
            default:
                robots[command.robotNumber]->AddCommand(command);
                break;
        }
    }
};

void Base::ActivateRobot(int robotNumber, const Map &map) {
    if(robots[robotNumber] == nullptr) {
        robots[robotNumber] = new Robot(robotNumber, map);
        std::cout << BASE_STRING << ROBO_STRING << robotNumber << " SAIU EM MISSAO";
    }
    else
        std::cout << BASE_STRING << ROBO_STRING << robotNumber << " JA ESTA EM MISSAO";
};

void Base::ReturnRobot(int robotNumber) {
    if(robots[robotNumber] == nullptr)
        std::cout << BASE_STRING << ROBO_STRING << robotNumber << " NAO ESTA EM MISSAO";

    int returnedAliens = robots[robotNumber]->aliens;
    int returnedResources = robots[robotNumber]->resources;
    delete robots[robotNumber];

    std::cout << BASE_STRING << ROBO_STRING << robotNumber << " RETORNOU ALIENS " << returnedAliens << " RECURSOS " << returnedResources;

    aliens += returnedAliens;
    resources += returnedResources;
};

void Base::FinalReport() {
    std::cout << BASE_STRING << "TOTAL DE ALIENS " << aliens << " RECURSOS " << resources;
}