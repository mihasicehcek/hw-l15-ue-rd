#include "clan.h"
#include <iostream>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include "console_utils.h"
#include "player.h"

Clan::Clan(short clanNumber, const std::string& color) : clanNumber(clanNumber), color(color) {}

std::string Clan::getColor() const {
    return this->color;
}

short Clan::getClanNumber() const {
    return clanNumber;
}
