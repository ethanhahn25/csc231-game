#pragma once
#include "action.h"
#include "vec.h"
#include "engine.h"
#include "entity.h"


class Move: public Action{
public:
    Move(Vec direction);
    Result perform (Engine& engine, std::shared_ptr<Entity> entity) override;
    Vec direction;
};