#pragma once
#include "animatedsprite.h"
#include "event.h"
#include "vec.h"

class Fireball : public Event {
public:
    Fireball(Sprite& sprite, Vec direction, int damage, Vec start_position, Vec end_position);
    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;

private:
    Sprite& weapon;
    Vec direction;
    int damage;
    Vec position;
    Sprite projectile;
};