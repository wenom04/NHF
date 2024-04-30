#include <iostream>
#include "Genericteam.h"

GenericTeam::GenericTeam(std::string name, int numberOfPlayers, std::string sport)
    : Team(name, numberOfPlayers), sport(sport) {
}

void GenericTeam::printTeamData() {
    std::cout << name << std::endl;
    std::cout << "Jatekosok szama: " << numberOfPlayers << std::endl;
}

void GenericTeam::addPlayer(Player* player){
    Player** temp = new Player*[numberOfPlayers+1];
    for (int i = 0; i < numberOfPlayers; i++){
        temp[i] = players[i];
    }
    temp[numberOfPlayers] = player;
    delete[] players;
    players = temp;
    numberOfPlayers++;
}

void GenericTeam::removePlayer(int jerseyNumber){
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

std::string GenericTeam::sportName(){
    return "generic";
}