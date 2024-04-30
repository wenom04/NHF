#include <iostream>
#include "Player.h"
#include "Football.h"
#include "Team.h"

Football::Football(std::string name, int numberOfPlayers, std::string coach, std::string assistantCoach) : Team(name, numberOfPlayers) {
    
    this->coach = coach;
    this->assistantCoach = assistantCoach;
}

void Football::printTeamData() {
    std::cout << name << std::endl;
    std::cout << "Jatekosok szama: " << numberOfPlayers << std::endl;
    std::cout << "Edzo: " << coach << std::endl;
    std::cout << "Masodedzo: " << assistantCoach << std::endl;
    std::cout << std::endl;
}

void Football::printFirstEleven() {
    std::cout << "Első 11:" << std::endl;
    for (int i = 0; i < 11; i++) {
        first11[i]->printData();
    }
}

void Football::addPlayer(Player* player){
    Player** temp = new Player*[numberOfPlayers+1];
    for (int i = 0; i < numberOfPlayers; i++){
        temp[i] = players[i];
    }
    temp[numberOfPlayers] = player;
    delete[] players;
    players = temp;
    numberOfPlayers++;
}

void Football::removePlayer(int jerseyNumber){
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

void Football::setFirst11(int* jerseyNumbers){
    first11 = new Player*[11];
    for (int i = 0; i < 11; i++){
        first11[i] = getPlayerByJerseyNumber(jerseyNumbers[i]);
    }
}

std::string Football::sportName(){
    return "football";
}

Football::~Football() {
    delete[] first11;
}
