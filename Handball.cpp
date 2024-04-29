#include "Handball.h"
#include "Team.h"
#include <iostream>

Handball::Handball(std::string name, int numberOfPlayers, int amountOfSupport) : Team(name, numberOfPlayers) {
    this->amountOfSupport = amountOfSupport;
}

void Handball::printTeamData() {
    std::cout << name << std::endl;
    std::cout << "Jatekosok szama: " << numberOfPlayers << std::endl;
    std::cout << "A csapat havi tamogatasa: " << amountOfSupport << std::endl;
    std::cout << std::endl;
}

void Handball::addPlayer(Player* player){
    Player** temp = new Player*[numberOfPlayers+1];
    for (int i = 0; i < numberOfPlayers; i++){
        temp[i] = players[i];
    }
    temp[numberOfPlayers] = player;
    delete[] players;
    players = temp;
    numberOfPlayers++;
}

void Handball::removePlayer(int jerseyNumber){
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

void Handball::setFirst7(int* jerseyNumbers){
    first7 = new Player*[7];
    for (int i = 0; i < 7; i++){
        first7[i] = getPlayerByJerseyNumber(jerseyNumbers[i]);
    }
}

std::string Handball::sportName(){
    return "handball";
}