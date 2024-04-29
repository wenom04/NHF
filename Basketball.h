#ifndef SPORTEGYESULET_BASKETBALL_H
#define SPORTEGYESULET_BASKETBALL_H

#include "Team.h"

class Basketball : public Team {
    int pomPomGirlsNumber;
    Player **first5 = nullptr;
public:
    Basketball(std::string name, int numberOfPlayers, int pomPonGirlsNumber);
    
    void printTeamData();
    
    void addPlayer(Player *player);
    
    void removePlayer(int jerseyNumber);
    
    void setFirst5(int *jerseyNumbers);

    std::string sportName();
    
    ~Basketball() override {};
};

#endif //SPORTEGYESULET_BASKETBALL_H
