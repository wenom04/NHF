#ifndef SPORTEGYESULET_GENERICTEAM_H
#define SPORTEGYESULET_GENERICTEAM_H
#include <iostream>
#include "Team.h"

class GenericTeam : public Team {
public:
    GenericTeam(std::string name, int numberOfPlayers);

    void printTeamData();

    void addPlayer(Player *player);
    
    void removePlayer(int jerseyNumber);

    std::string sportName();
};

#endif