#pragma once

#include "action.h"
#include "vec.h"
#include "door.h"

class Opendoor : public Action {
public:
    Opendoor(Door&);
    Result perform(Engine& engine, std::shared_ptr<Entity> entity) override;
    Door& door;
};