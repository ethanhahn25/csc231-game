#pragma once
#include "weapon.h"

class Mace : public Weapon {
public:
    Mace(int damage);

    void use(Engine& engine, Entity& attacker, Entity& defender) override;
};