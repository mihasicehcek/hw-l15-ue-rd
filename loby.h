#pragma once
#include <map>
#include <memory>
#include <vector>
#include "player.h"

#include "clan.h"

struct Loby {
private:
    std::vector<std::unique_ptr<Clan>> clans;
    std::map<size_t, std::vector<std::unique_ptr<Player>>> clansPlayers;

public:
    explicit Loby(std::vector<std::unique_ptr<Clan>> clans);

    Clan* getClanByIndex(size_t index);

    void addPlayer(std::unique_ptr<Player> player);

    void removePlayer(const Player* player);
    void removePlayer(short clanNumber, const std::string& name);

    Player* getPlayer(short clanNumber, size_t index);

    size_t getPlayersCount(short clanNumber) const;

    Player* getMostAttractiveForAttack(short clanNumber) const;

    void printClansInfo() const;

    bool isClanEmpty(short clanNumber) const;
};
