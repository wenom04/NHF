#include <iostream>
#include "Player.h"

Player::Player(std::string name, int age, int jerseyNumber, int height, int weight){
    this->name = name;
    this->age = age;
    this->jerseyNumber = jerseyNumber;
    this->height = height;
    this->weight = weight;
}

void Player::printData(){
    std::cout << "Nev: " << name << std::endl;
    std::cout << "Eletkor: " << age << std::endl;
    std::cout << "Mezszam: " << jerseyNumber << std::endl;
    std::cout << "Magassag: " << height << std::endl;
    std::cout << "Suly: " << weight << std::endl;
}

int Player::getJerseyN() const{
    return jerseyNumber;
}

std::string Player::getName() const{
    return name;
}

void Player::setFreeAgentStatus(bool freeAgent){
    this->freeAgent = freeAgent;
}

