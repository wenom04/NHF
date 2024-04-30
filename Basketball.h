#ifndef SPORTEGYESULET_BASKETBALL_H
#define SPORTEGYESULET_BASKETBALL_H

#include "Team.h"

class Basketball : public Team {
    int pomPomGirlsNumber;
    Player **first5 = nullptr;
public:
    Basketball(std::string name, int numberOfPlayers, int pomPonGirlsNumber);
    
    void printTeamData() override;
    
    void addPlayer(Player *player) override;
    
    void removePlayer(int jerseyNumber) override;
    
    void setFirst5(int *jerseyNumbers);

    std::string sportName() override;
    
    ~Basketball() {};
};

#endif //SPORTEGYESULET_BASKETBALL_H
