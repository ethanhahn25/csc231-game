#include "closedoor.h"
#include "engine.h"
#include "entity.h"
#include "audioevent.h"
#include "updatefov.h"

Result Closedoor::perform(Engine& engine, std::shared_ptr<Entity> entity){
    Vec position = entity->get_position();
    std::vector<Vec> neighbors = engine.dungeon.neighbors(position);

    bool closed_any_doors = false;
    for(Vec pos : neighbors){
        Tile& tile = engine.dungeon.get_tile(pos);
        if(tile.has_door() && tile.door->is_open()){
            Door& door = *tile.door;
            door.close();
            closed_any_doors = true;
        }
    }
    if(closed_any_doors){
        engine.events.create_event<UpdateFOV>();
        engine.events.create_event<AudioEvent>("door-close");
        return success();
    }
    else{
        return failure();
    }
}