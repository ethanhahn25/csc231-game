#pragma once
#include "action.h"

class Projectile : public Action {
public:
    // Projectile(std::shared_ptr<Entity> entity);
    Result perform(Engine& engine, std::shared_ptr<Entity> entity) override;

private:
    // std::shared_ptr<Entity> attacker;
};