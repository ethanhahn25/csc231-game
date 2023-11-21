#pragma once
#include "weapon.h"

class Staff : public Weapon {
public:
    Staff(int damage);

    void use(Engine& engine, Entity& attacker, Entity& defender) override;


};