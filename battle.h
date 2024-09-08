#pragma once
#include "clan.h"
#include "loby.h"

struct TurnActors {
    Player* attacker;
    Player* deffender;
};

struct Battle {
private:
    Loby* loby;
    size_t playerFromClan1Index = 0;
    size_t playerFromClan2Index = 0;
    bool turnFirstClan = true;

    void turn();

    TurnActors getNextTurnActors();
public:
    Battle(Loby* loby);

    void simulateBattle();
};
