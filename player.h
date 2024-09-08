#pragma once
#include <string>

struct Player {
private:
    float currentHealth;
    std::string name;
    float maxHealth;
    float damage;
    short clan;

public:
    Player(
        const std::string& name,
        float maxHealth,
        float damage,
        short clan
        );

    [[nodiscard]] const std::string& getName() const;

    short getClan() const;

    [[nodiscard]] float getDamage() const;

    [[nodiscard]] float getHealth() const;

    [[nodiscard]] float getMaxHealth() const;

    float recieveDamage(float damage);

    [[nodiscard]] bool isAlive() const;

    [[nodiscard]] float getObservedHealth() const;

    [[nodiscard]] float getAttractivenessForAttackCooficient() const;
};
