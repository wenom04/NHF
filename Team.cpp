#include "Team.h"

Team::Team(std::string name, int numberOfPlayers){
    this->name = name;
    this->numberOfPlayers = numberOfPlayers;
    players = new Player*[numberOfPlayers];
    for (int i = 0; i < numberOfPlayers; i++){
        players[i] = nullptr;
    }
}

int Team::getNumberOfPlayers(){
    return numberOfPlayers;
}

std::string Team::getName(){
    return name;
}

Player* Team::getPlayerByJerseyNumber(int jerseyNumber){
    for (int i = 0; i < numberOfPlayers; i++){
        if(players[i] != nullptr && players[i]->getJerseyN() == jerseyNumber){
            return players[i];
        }
    }
    return nullptr;
}

void Team::setPlayersFreeAgentStatus(){
    bool freeagent = false;
    for (int i = 0; i < numberOfPlayers; i++){
        if (players[i] != nullptr)
            players[i]->setFreeAgentStatus(freeagent);
    }
}

Team::~Team() {
    for (int i = 0; i < numberOfPlayers; i++) {
        if (players != nullptr)
            delete players[i];
    }
    delete[] players;
}