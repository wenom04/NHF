#include <iostream>
#include "Club.h"

Club::Club(std::string name) {
    this->name = name;
    this->numberOfTeams = 0;
    this->teams = nullptr;
}

std::string Club::getName() {
    return name;
}

int Club::getNumberOfTeams() {
    return numberOfTeams;
}

void Club::listTeams() {
    for (int i = 0; i < numberOfTeams; i++) {
        teams[i]->printTeamData();
    }
}

Team* Club::getTeamByName(std::string teamName){
    for (int i = 0; i < numberOfTeams; i++){
        if(teams[i]->getName() == teamName)
            return teams[i];
    }
    return nullptr;
}

void Club::addTeam(Team *team) {
    Team** temp = new Team*[numberOfTeams + 1];
    for (int i = 0; i < numberOfTeams; i++){
        temp[i] = teams[i];
    }
    temp[numberOfTeams] = team;
    delete[] teams;
    teams = temp;
    numberOfTeams++;
}

void Club::removeTeam(std::string teamName){
    Team** temp = new Team*[numberOfTeams - 1];
    int idx = 0;
    bool found = false;
    for (int i = 0; i < numberOfTeams; i++){
        if (teams[i]->getName() == teamName){
            delete teams[i];
            found = true;
            continue;
        }
        else{
            temp[idx] = teams[i];
            idx++;           
        }
    } 
    if(found){
        delete[] teams;
        teams = temp;
        numberOfTeams--;
    }
    else{
        delete[] temp;
        std::cout << "Nincs ilyen nevu csapat!";
    }
}

Club::~Club(){
    for (int i = 0; i < numberOfTeams; i++)
        delete teams[i];
    delete[] teams;
}