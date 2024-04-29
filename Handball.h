#ifndef SPORTEGYESULET_HANDBALL_H
#define SPORTEGYESULET_HANDBALL_H

#include "Team.h"

class Handball : public Team {
    int amountOfSupport;
    Player **first7 = nullptr;
public:
    Handball(std::string name, int numberOfPlayers, int amountOfSupport);
    
    void printTeamData();
    
    void addPlayer(Player *player);
    
    void removePlayer(int jerseyNumber);
    
    void setFirst7(int *jerseyNumbers);

    std::string sportName();
    
    ~Handball() {};
};

#endif //SPORTEGYESULET_HANDBALL_H
