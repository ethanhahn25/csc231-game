#pragma once

#include "event.h"
#include "vec.h"
#include "sprite.h"

class Thrust : public Event {
public:
    Thrust(Sprite& sprite, Vec direction);

    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;

private:
    Sprite& sprite; //weapon sprite, will be modified
    Sprite copy;
    Vec direction;
};