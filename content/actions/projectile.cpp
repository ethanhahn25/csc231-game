#include "projectile.h"
#include "engine.h"
#include "entity.h"
#include "fireball.h"
#include "sprite.h"
#include "vec.h"
#include "weapon.h"

Result Projectile::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    Vec direction = entity->get_direction();
    Vec position = entity->get_position() + direction;
    Tile tile = engine.dungeon.tiles(position);
    while (!tile.entity && !tile.is_wall()) {
        if (tile.has_door()) {
            Door door = *tile.door;
            if (!(door.is_open())) {
                break;
            }
        }

        position = position + direction;
        if (engine.dungeon.tiles.within_bounds({position.x, position.y})) {
            tile = engine.dungeon.tiles(position);
        }
    }
    if (tile.has_entity()) {
        std::shared_ptr<Weapon> weapon = entity->get_weapon();
        weapon->use(engine, *entity, *tile.entity);
    } else {
        Sprite sprite = engine.graphics.get_sprite("staff_red");
        engine.events.create_event<Fireball>(sprite, direction, 4, entity->get_position(),
                                             position);
    }
    return success();
}