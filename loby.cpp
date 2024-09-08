
#include "loby.h"

#include <algorithm>
#include <iostream>

#include "clan.h"
#include "player.h"
#include "console_utils.h"

Loby::Loby(std::vector<std::unique_ptr<Clan>> clans) {
    this->clans = std::move(clans);
}

void Loby::addPlayer(std::unique_ptr<Player> player) {
    clansPlayers[player->getClan()].push_back(std::move(player));
}

Clan* Loby::getClanByIndex(size_t index) {
    return clans[index].get();
}


void Loby::removePlayer(const Player *player) {
    removePlayer(player->getClan(), player->getName());
}

void Loby::removePlayer(const short clanNumber, const std::string &name) {
    auto& players = clansPlayers.at(clanNumber);

    auto it = std::find_if(players.begin(), players.end(),
        [&name](const std::unique_ptr<Player>& player) {
            return player->getName() == name;
        });

    if (it != players.end()) {
        players.erase(it);
    }
}

Player* Loby::getPlayer(const short clanNumber, const size_t index) {
    return clansPlayers.at(clanNumber).at(index).get();
}

Player* Loby::getMostAttractiveForAttack(const short clanNumber) const {
    Player* mostAttractive = clansPlayers.at(clanNumber)[0].get();
    for (auto& player : clansPlayers.at(clanNumber)) {
        if (player->getAttractivenessForAttackCooficient() > mostAttractive->getAttractivenessForAttackCooficient()) {
            mostAttractive = player.get();
        }
    }
    return mostAttractive;
}

size_t Loby::getPlayersCount(const short clanNumber) const {
    if(isClanEmpty(clanNumber)) {
        return 0;
    }
    return clansPlayers.at(clanNumber).size();
}

bool Loby::isClanEmpty(const short clanNumber) const {
    return  clansPlayers.find(clanNumber) == clansPlayers.end() || clansPlayers.at(clanNumber).empty();
}


void Loby::printClansInfo() const {
    std::cout << "Clans info:" << std::endl;
    for (const auto& clan : clans) {
        setConsoleTextColor(clan->getColor());
        std::cout << "Clan " << clan->getClanNumber() << std::endl;
        setConsoleTextColor("white");
        if (isClanEmpty(clan->getClanNumber())) {
            std::cout << "No active players in this clan" << std::endl;
        } else {
            for (const auto& player : clansPlayers.at(clan->getClanNumber())) {
                std::cout << "Player ";
                setConsoleTextColor(clan->getColor());
                std::cout << player->getName();
                setConsoleTextColor("white");
                std::cout << " health: " << player->getHealth() << "/" << player->getMaxHealth();
                std::cout << " damage: " << player->getDamage() << std::endl;
            }
        }
        std::cout << std::endl;
    }
}
