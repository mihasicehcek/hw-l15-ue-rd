#pragma once
#include <string>

struct Clan {
private:
    short clanNumber;
    std::string color;

public:
    Clan(short clanNumber, const std::string& color);

    short getClanNumber() const;

    [[nodiscard]] std::string getColor() const;
};
