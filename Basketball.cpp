#include "Basketball.h"
#include "Team.h"
#include <iostream>

Basketball::Basketball(std::string name, int numberOfPlayers, int pomPomGirlsNumber) : Team(name, numberOfPlayers) {
    this->pomPomGirlsNumber = pomPomGirlsNumber;
}

void Basketball::printTeamData() {
    std::cout << name << std::endl;
    std::cout << "Jatekosok szama: " << numberOfPlayers << std::endl;
    std::cout << "Pom-Pom lanyok szama: " << pomPomGirlsNumber << std::endl;
    std::cout << std::endl;
}

void Basketball::addPlayer(Player* player){
    Player** temp = new Player*[numberOfPlayers+1];
    for (int i = 0; i < numberOfPlayers; i++){
        temp[i] = players[i];
    }
    temp[numberOfPlayers] = player;
    delete[] players;
    players = temp;
    numberOfPlayers++;
}

void Basketball::removePlayer(int jerseyNumber){
    Player** temp = new Player*[numberOfPlayers - 1];
    int idx = 0;
    bool found = false;
    for (int i = 0; i < numberOfPlayers; i++){
        if(players[i]->getJerseyN() == jerseyNumber){
            delete players[i];
            found = true;
        }
        else{
            temp[idx] = players[i];
            idx++;
        }
    }
    if(found){
        delete[] players;
        players = temp;
        numberOfPlayers--;
    }
    else{
        delete[] temp;
        std::cout << "Nincs ilyen mezszamu jatekos!";
    }
}

void Basketball::setFirst5(int* jerseyNumbers){
    first5 = new Player*[5];
    for (int i = 0; i < 5; i++){
        first5[i] = getPlayerByJerseyNumber(jerseyNumbers[i]);
    }
}

std::string Basketball::sportName(){
    return "basketball";
}