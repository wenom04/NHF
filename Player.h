#ifndef SPORTEGYESULET_PLAYER_H
#define SPORTEGYESULET_PLAYER_H

#include <string>

class Player {
    std::string name;
    int age;
    int jerseyNumber;
    int height;
    int weight;
    bool freeAgent = false;
public:
    Player(std::string name, int age, int jerseyNumber, int height, int weight);
    
    void printData();
    
    int getJerseyN() const;
    
    std::string getName() const;
    
    void setFreeAgentStatus(bool freeAgent);
    
    ~Player() {};
};

#endif //SPORTEGYESULET_PLAYER_H
