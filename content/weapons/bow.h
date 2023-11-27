#pragma once
#include "weapon.h"

class Bow : public Weapon {
public:
    Bow(int damage);

    void use(Engine& engine, Entity& attacker, Entity& defender) override;
};