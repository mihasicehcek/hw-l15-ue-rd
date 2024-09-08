#include <cmath>
#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include "clan.h"
#include "player.h"
#include "battle.h"
#include "loby.h"


void addPlayer2Clan(std::unique_ptr<Loby>& loby) {
    std::string name;
    short clanNumber;
    float maxHealth;
    float damage;

    std::cin >> name >> clanNumber >> maxHealth >> damage;

    auto player = std::make_unique<Player>(name, maxHealth, damage, clanNumber);
    loby->addPlayer(std::move(player));
}

void removePlayer(std::unique_ptr<Loby>& loby) {
    std::string name;
    short clanNumber;

    std::cin >> name >> clanNumber;
    loby->removePlayer(clanNumber, name);
}

int main() {
    std::cout
    << "0: Add player to clan; Name ClanNumber MaxHealth Damage" << std::endl
    << "1: Remove player from clan; Name ClanNumber" << std::endl
    << "2: Simulate battle" << std::endl;

    std::vector<std::unique_ptr<Clan>> clans;
    clans.push_back(std::make_unique<Clan>(0, "yellow"));
    clans.push_back(std::make_unique<Clan>(1, "blue"));

    auto loby = std::make_unique<Loby>(std::move(clans));
    auto battle = std::make_unique<Battle>(loby.get());

    bool running = true;
    while (running) {
        int mode;

        std::cin >> mode;
        switch (mode) {
            case 0: addPlayer2Clan(loby); break;
            case 1: removePlayer(loby); break;
            case 2: battle->simulateBattle(); running=false; break;
            default: std::cerr << "Invalid mode" << std::endl; break;
        }
    }

    return 0;
}

