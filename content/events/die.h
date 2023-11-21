#pragma once

#include "event.h"

#include "entity.h"

class Entity;

class Die : public Event {
public:
    Die(Entity& entity);
    void execute(Engine& engine) override;
private:
    Entity& entity;
};
