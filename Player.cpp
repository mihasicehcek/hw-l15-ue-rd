#include <cmath>

#include "player.h"

Player::Player(
    const std::string& name,
    float maxHealth,
    float damage,
    short clan
    ) {
    this->name = name;
    this->maxHealth = maxHealth;
    this->currentHealth = maxHealth;
    this->damage = damage;
    this->clan = clan;
}

float Player::getDamage() const {
    return damage;
}

float Player::getHealth() const {
    return currentHealth;
}

float Player::getMaxHealth() const {
    return maxHealth;
}

const std::string& Player::getName() const {
    return name;
}

bool Player::isAlive() const {
    return currentHealth > 0;
}

short Player::getClan() const {
    return clan;
}

float Player::recieveDamage(const float damage) {
    currentHealth -= damage;
    if (currentHealth < 0) {
        currentHealth = 0;
    }
    return currentHealth;
}

float Player::getObservedHealth() const {
    return std::ceil(this->currentHealth  / 10) * 10;
}

float Player::getAttractivenessForAttackCooficient() const {
    return getObservedHealth() / damage;
}
