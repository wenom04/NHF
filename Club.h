#ifndef SPORTEGYESULET_CLUB_H
#define SPORTEGYESULET_CLUB_H

#include <string>
#include "Team.h"

class Club {
    std::string name;
    Team **teams = nullptr;
    int numberOfTeams = 0;
public:
    Club(std::string name);

    std::string getName();

    int getNumberOfTeams();
    
    void listTeams();

    Team* getTeamByName(std::string teamName);
    
    void addTeam(Team *team);
    
    void removeTeam(std::string teamName);
    
    ~Club();
};

#endif //SPORTEGYESULET_CLUB_H
