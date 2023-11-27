#include "opendoor.h"
#include "engine.h"
#include "entity.h"

#include "updatefov.h"

Opendoor::Opendoor(Door& door)
    :door{door}{}

Result Opendoor::perform(Engine& engine, std::shared_ptr<Entity> entity){
    if(!door.is_open()){
        door.open();
        engine.events.create_event<UpdateFOV>();
        return success();
    }
    return failure();
}