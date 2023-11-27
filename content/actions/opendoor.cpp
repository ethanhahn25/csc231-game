#include "opendoor.h"
#include "engine.h"
#include "entity.h"

#include "updatefov.h"

Opendoor::Opendoor(Vec position)
    :position{position}{}

Result Opendoor::perform(Engine& engine, std::shared_ptr<Entity> entity){
    bool open_any_doors = false;
        Tile& tile = engine.dungeon.get_tile(position);
        if(tile.has_door() && !tile.door->is_open()){
            Door& door = *tile.door;
            door.open();
            open_any_doors = true;
        }

    if(open_any_doors){
        engine.events.create_event<UpdateFOV>();
        return success();
    }
    else{
        return failure();
    }
}