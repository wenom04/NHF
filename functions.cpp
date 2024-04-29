#include <iostream>
#include "functions.h"

void printOutPassword(){
    std::cout << "Kerem a jelszot!" << std::endl;
    std::cout << "Jelszo: ";
}

void printOutMenu(){
    std::cout << "Mit szeretne csinalni az adatokkal?" << std::endl;
    std::cout << "1: Csapatok kilistazasa" << std::endl;
    std::cout << "2: Csapat felvetele" << std::endl;
    std::cout << "3: Csapat torlese" << std::endl;
    std::cout << "4: Meglevo csapat adatainak modositasa" << std::endl;
    std::cout << "5: Adatok modositasanak befejezese" << std::endl;
}

void printOutModifying(){
    std::cout << "1: Kezdocsapat beallitasa" << std::endl;
    std::cout << "2: Jatekos hozzaadasa" << std::endl;
    std::cout << "2: Jatekos torlese" << std::endl;
}

