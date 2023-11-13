#include "move.h"

Move::Move(Vec direction)
    :direction{direction}{}

Result Move::perform(Engine& engine, std::shared_ptr<Entity> entity){
    Vec new_pos = entity->get_position() + direction;
    Tile& tile = engine.dungeon.get_tile(new_pos);
    if(tile.is_wall() || tile.has_door() || tile.has_entity()) {
        return failure();
    }
    entity->move_to(new_pos);
    entity->change_direction(direction);
    return success();
}

