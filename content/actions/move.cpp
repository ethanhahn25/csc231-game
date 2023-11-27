#include "move.h"
#include "rest.h"
#include "opendoor.h"
#include "attack.h"

Move::Move(Vec direction)
    :direction{direction}{}

Result Move::perform(Engine& engine, std::shared_ptr<Entity> entity){
    Vec new_pos = entity->get_position() + direction;
    Tile& tile = engine.dungeon.get_tile(new_pos);
    if(tile.is_wall()) {
        return failure();
    }
    if(tile.has_entity()){
        return alternative(Attack(*tile.entity));
    }
    if(tile.has_door()){
        Door& door = *tile.door;
        if(!door.is_open()){
            return alternative(Opendoor(door)); //pass door object&
        }
    }

    entity->move_to(new_pos);
    entity->change_direction(direction);
    return success();
}


