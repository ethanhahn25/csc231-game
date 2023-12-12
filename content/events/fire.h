#pragma once
#include "event.h"
#include "vec.h"
#include "animatedsprite.h"

class Fire : public Event {
public:
    Fire(Vec position);
    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;

private:
    Vec position;
    const int damage = 5;
    AnimatedSprite sprite;
};
