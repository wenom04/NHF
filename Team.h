#ifndef SPORTEGYESULET_TEAM_H
#define SPORTEGYESULET_TEAM_H

#include <string>
#include "Player.h"

class Team {
protected:
    std::string name;
    int numberOfPlayers;
    Player **players = nullptr;
public:
    Team(std::string name, int numberOfPlayers);

    virtual void printTeamData() = 0;

    virtual void addPlayer(Player *player) = 0;

    virtual void removePlayer(int jerseyNumber) = 0;

    virtual std::string sportName() = 0;

    virtual ~Team();

    int getNumberOfPlayers();

    std::string getName();

    Player* getPlayerByJerseyNumber(int jerseyNumber);

    void setPlayersFreeAgentStatus();
};

#endif //SPORTEGYESULET_TEAM_H
