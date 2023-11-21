#pragma once

#include "action.h"
#include "vec.h"

class Opendoor : public Action {
public:
    Opendoor(Vec);
    Result perform(Engine& engine, std::shared_ptr<Entity> entity) override;
    Vec position;
};