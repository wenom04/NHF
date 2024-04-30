#include <iostream>
#include "Club.h"
#include "Team.h"
#include "Basketball.h"
#include "Football.h"
#include "Player.h"
#include "Handball.h"
#include "Genericteam.h"
#include "functions.h"

int main() {
    Club club("Fitt Sportegyesulet");

    std::cout << club.getName() << std::endl;
    std::cout << club.getNumberOfTeams() << std::endl;

    Basketball *basketball = new Basketball("Kosarlabda csapat", 5, 3);
    Football *football = new Football("Real Madrid", 23, "Carlo Ancelotti", "Davide Ancelotti");
    Handball *handball = new Handball("Kezi csapat", 10, 350000);
    GenericTeam *genteam = nullptr;

    Player *player = nullptr;
    //
    int height;
    int weight;
    int age;
    std::string name;
    int jerseyNumber;
    //
    club.addTeam(basketball);
    club.addTeam(football);
    club.addTeam(handball);

    bool remove = false; //4321
    bool add = false; //5678
    bool list = false; //1234
    bool isRunning = false;
    bool isModifying = false;
    int n;
    int k;
    int m;

    int removenumber;
    printOutPassword();

    std::cin >> n;

    switch (n) {
        case 4321:
            remove = true;
        case 5678:
            add = true;
        case 1234:
            list = true;
            isRunning = true;
            break;
        default:
            std::cout << "Az adatokhoz valo hozzaferes megtagadva!" << std::endl;
            break;
    }

    while (isRunning) {
        printOutMenu();

        std::cin >> k;

        int teamnumber;
        std::string teamname;
        std::string removeteam;
        std::string modifyteam;
        std::string  sport;

        switch (k) {
            case 1:
                if (list)
                    club.listTeams();
                break;
            case 2:
                if (add) {
                    std::cout << "A csapat neve: " << std::endl;
                    std::cin >> std::ws; //https://cplusplus.com/forum/beginner/25265/
                    std::getline(std::cin, teamname);
                    std::cout << "A csapat alapletszama: " << std::endl;
                    std::cin >> teamnumber;
                    std::cout << "A csapat sportaga: " << std::endl;
                    std::cin >> std::ws;
                    std::getline(std::cin, sport);

                    genteam = new GenericTeam(teamname, teamnumber, sport);
                    club.addTeam(genteam);
                } else
                    std::cout << "Ezzel a jelszoval nem tud csapatot hozzaadni" << std::endl;
                break;
            case 3:
                if (remove) {
                    std::cout << "Melyik csapatot szeretne torolni?" << std::endl;
                    club.listTeams();
                    std::cin >> std::ws;
                    std::getline(std::cin, removeteam);
                    club.removeTeam(removeteam);
                } else
                    std::cout << "Ezzel a jelszoval nem tud csapatot torolni" << std::endl;
                break;
            case 4:
                std::cout << "Melyik csapat adatait szeretne modositani" << std::endl;
                club.listTeams();
                std::cin >> std::ws;
                std::getline(std::cin, modifyteam);
                isModifying = true;
                break;
            case 5:
                isRunning = false;
                break;
            default:
                std::cout << "Nem helyes szam!" << std::endl;
        }
        int firstfootball[11];
        int firsthandball[7];
        int firstbasketball[5];
        if (isModifying) {
            printOutModifying();
            std::cin >> m;
            switch (m) {
                case 1:
                    if (club.getTeamByName(modifyteam)->sportName() == "football") {
                        std::cout << "Irjon ide 11 db szamot" << std::endl;
                        for (int i = 0; i < 11; i++) {
                            std::cin >> firstfootball[i];
                        }
                        football->setFirst11(firstfootball);
                        football->printFirstEleven();
                    }

                    if (club.getTeamByName(modifyteam)->sportName() == "handball") {
                        std::cout << "Irjon ide 7 db szamot" << std::endl;
                        for (int i = 0; i < 7; i++) {
                            std::cin >> firsthandball[i];
                        }
                        handball->setFirst7(firsthandball);
                    }

                    if (club.getTeamByName(modifyteam)->sportName() == "basketball") {
                        std::cout << "Irjon ide 5 db szamot" << std::endl;
                        for (int i = 0; i < 5; i++) {
                            std::cin >> firstbasketball[i];
                        }
                        basketball->setFirst5(firstbasketball);
                    }

                    if (club.getTeamByName(modifyteam)->sportName() == "generic") {
                        std::cout << "Sajnos ezekhez a csapatokhoz meg nem lehet beallitani kezdocsapatot!"
                                  << std::endl;
                    }
                    isModifying = false;
                    break;
                case 2:
                    if (club.getTeamByName(modifyteam)->sportName() == "football") {
                        std::cout << "A jatekos neve: " << std::endl;
                        std::cin >> std::ws;
                        std::getline(std::cin, name);
                        std::cout << "A jatekos eletkora: " << std::endl;
                        std::cin >> age;
                        std::cout << "A jatekos mezszama: " << std::endl;
                        std::cin >> jerseyNumber;
                        std::cout << "A jatekos magassaga: " << std::endl;
                        std::cin >> height;
                        std::cout << "A jatekos sulya: " << std::endl;
                        std::cin >> weight;
                        player = new Player(name, age, jerseyNumber, height, weight);
                        football->addPlayer(player);
                    }

                    if (club.getTeamByName(modifyteam)->sportName() == "handball") {
                        std::cout << "A jatekos neve: " << std::endl;
                        std::cin >> std::ws;
                        std::getline(std::cin, name);
                        std::cout << "A jatekos eletkora: " << std::endl;
                        std::cin >> age;
                        std::cout << "A jatekos mezszama: " << std::endl;
                        std::cin >> jerseyNumber;
                        std::cout << "A jatekos magassaga: " << std::endl;
                        std::cin >> height;
                        std::cout << "A jatekos sulya: " << std::endl;
                        std::cin >> weight;
                        player = new Player(name, age, jerseyNumber, height, weight);
                        handball->addPlayer(player);
                    }

                    if (club.getTeamByName(modifyteam)->sportName() == "basketball") {
                        std::cout << "A jatekos neve: " << std::endl;
                        std::cin >> std::ws;
                        std::getline(std::cin, name);
                        std::cout << "A jatekos eletkora: " << std::endl;
                        std::cin >> age;
                        std::cout << "A jatekos mezszama: " << std::endl;
                        std::cin >> jerseyNumber;
                        std::cout << "A jatekos magassaga: " << std::endl;
                        std::cin >> height;
                        std::cout << "A jatekos sulya: " << std::endl;
                        std::cin >> weight;
                        player = new Player(name, age, jerseyNumber, height, weight);
                        basketball->addPlayer(player);
                    }

                    if (club.getTeamByName(modifyteam)->sportName() == "generic") {
                        if (genteam == nullptr)
                            std::cout << "Gond van ocsi" << std::endl;
                        std::cout << "A jatekos neve: " << std::endl;
                        std::cin >> std::ws;
                        std::getline(std::cin, name);
                        std::cout << "A jatekos eletkora: " << std::endl;
                        std::cin >> age;
                        std::cout << "A jatekos mezszama: " << std::endl;
                        std::cin >> jerseyNumber;
                        std::cout << "A jatekos magassaga: " << std::endl;
                        std::cin >> height;
                        std::cout << "A jatekos sulya: " << std::endl;
                        std::cin >> weight;
                        player = new Player(name, age, jerseyNumber, height, weight);
                        genteam->addPlayer(player);
                    }
                    isModifying = false;
                    break;
                case 3:
                    std::cout << "Irjon be egy mezszamot" << std::endl;
                    std::cin >> removenumber;
                    if (club.getTeamByName(modifyteam)->sportName() == "football")
                        football->removePlayer(removenumber);
                    if (club.getTeamByName(modifyteam)->sportName() == "handball")
                        handball->removePlayer(removenumber);
                    if (club.getTeamByName(modifyteam)->sportName() == "basketball")
                        basketball->removePlayer(removenumber);
                    if (club.getTeamByName(modifyteam)->sportName() == "generic")
                        genteam->removePlayer(removenumber);
                    isModifying = false;
                    break;
                default:
                    std::cout << "Ervenytelen szam!" << std::endl;
                    break;
            }
        }
    }

    return 0;
}