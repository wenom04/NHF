#ifndef SPORTEGYESULET_FOOTBALL_H
#define SPORTEGYESULET_FOOTBALL_H

#include <string>
#include "Team.h"

class Football : public Team {
    std::string coach;
    std::string assistantCoach;
    Player **first11 = nullptr;
public:
    Football(std::string name, int numberOfPlayers, std::string coach, std::string assistantCoach);
    
    void printTeamData();
    
    void printFirstEleven();

    void addPlayer(Player *player);

    void removePlayer(int jerseyNumber);

    void setFirst11(int *jerseyNumbers);
    
    std::string sportName();
    
    ~Football();
};

#endif //SPORTEGYESULET_FOOTBALL_H
