#include "move.h"
#include "rest.h"
#include "opendoor.h"

Move::Move(Vec direction)
    :direction{direction}{}

Result Move::perform(Engine& engine, std::shared_ptr<Entity> entity){
    Vec new_pos = entity->get_position() + direction;
    Tile& tile = engine.dungeon.get_tile(new_pos);
    if(tile.is_wall() || tile.has_door()) {
        return failure();
    }
    if(tile.has_entity()){
        return alternative(Rest{});
    }
    if(tile.has_door()){
        Door& door = *tile.door;
        if(!door.is_open()){
            return alternative(Opendoor(new_pos));
        }
    }

    entity->move_to(new_pos);
    entity->change_direction(direction);
    return success();
}
//kill entity on tiles not on team

