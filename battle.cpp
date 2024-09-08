#include "battle.h"
#include <iostream>
#include "clan.h"
#include "console_utils.h"
#include "loby.h"

void printTurnStatus(Loby* loby, const Player* attackingPlayer, const Player* deffendingPlayer) {
    std::cout << "Player ";
    setConsoleTextColor(loby->getClanByIndex(attackingPlayer->getClan())->getColor());
    std::cout << attackingPlayer->getName();
    setConsoleTextColor("white");
    std::cout << " attacks ";
    setConsoleTextColor(loby->getClanByIndex(attackingPlayer->getClan())->getColor());
    std::cout << deffendingPlayer->getName() << std::endl;
    setConsoleTextColor("white");

    std::cout << "Current health of ";
    setConsoleTextColor(loby->getClanByIndex(deffendingPlayer->getClan())->getColor());
    std::cout << deffendingPlayer->getName();
    setConsoleTextColor("white");
    std::cout << " is ";
    setConsoleTextColor("red");
    std::cout << deffendingPlayer->getHealth() << std::endl << std::endl;
    setConsoleTextColor("white");
}

void printDeathInfo(Loby* loby, const Player* deffendingPlayer) {
    setConsoleTextColor("red");
    std::cout << "Player ";
    setConsoleTextColor(loby->getClanByIndex(deffendingPlayer->getClan())->getColor());
    std::cout << deffendingPlayer->getName();
    setConsoleTextColor("red");
    std::cout << " is dead" << std::endl << std::endl;
    setConsoleTextColor("white");
}

void printClanWon(Clan* clan) {
    std::cout << "Clan ";
    setConsoleTextColor(clan->getColor());
    std::cout << clan->getColor();
    setConsoleTextColor("white");
    std::cout << " won!" << std::endl;
}

Battle::Battle(Loby *loby) : loby(loby) {}


TurnActors Battle::getNextTurnActors() {
    Clan* currentClan = turnFirstClan ? loby->getClanByIndex(0) : loby->getClanByIndex(1);
    Clan* opposingClan = turnFirstClan ? loby->getClanByIndex(1) : loby->getClanByIndex(0);
    size_t& currentPlayerIndex = turnFirstClan ? playerFromClan1Index : playerFromClan2Index;

    if (currentPlayerIndex >= loby->getPlayersCount(currentClan->getClanNumber())) {
        currentPlayerIndex = 0;
    }

    TurnActors turnActors = {
        loby->getPlayer(currentClan->getClanNumber(), currentPlayerIndex),
        loby->getMostAttractiveForAttack(opposingClan->getClanNumber())
    };

    currentPlayerIndex++;
    turnFirstClan = !turnFirstClan;

    return turnActors;
}

void Battle::turn() {
    TurnActors turnActors = getNextTurnActors();
    turnActors.deffender->recieveDamage(turnActors.attacker->getDamage());
    printTurnStatus(loby, turnActors.attacker, turnActors.deffender);

    if(!turnActors.deffender->isAlive()) {
        printDeathInfo(loby, turnActors.deffender);
        loby->removePlayer(turnActors.deffender);
    }
}

void Battle::simulateBattle() {
    loby->printClansInfo();

    while (loby->getPlayersCount(0) > 0 && loby->getPlayersCount(1) > 0) {
        turn();
    }

    if (loby->getPlayersCount(0) == 0 && loby->getPlayersCount(1) == 0) {
        std::cout << "Draw!" << std::endl;
    } else if (loby->getPlayersCount(1) == 0) {
        printClanWon(loby->getClanByIndex(0));
    } else {
        printClanWon(loby->getClanByIndex(1));
    }

    loby->printClansInfo();
}