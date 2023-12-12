#include "fireball.h"

#include "audioevent.h"
#include "engine.h"
#include "entity.h"
#include "hit.h"

Fireball::Fireball(Sprite& sprite, Vec direction, int damage, Vec start_position, Vec end_position)
    : //Event{distance(start_position, end_position)},
      weapon{sprite},
      direction{direction},
      damage{damage},
      start_position{start_position},
      end_position{end_position},
      position{direction + start_position} {}

void Fireball::execute(Engine& engine) {
    if (frame_count == 0) {
        projectile = engine.graphics.get_sprite("explosion");
    }
    engine.camera.add_overlay(position, projectile);
    position = position + direction;
}

void Fireball::when_done(Engine& engine) {
    if (engine.dungeon.tiles.within_bounds({position.x, position.y})) {
        {
            Tile tile = engine.dungeon.get_tile(position);
            if (tile.has_entity() && tile.entity->is_alive()) {
                Entity& entity = *tile.entity;
                engine.events.create_event<Hit>(entity, damage);
            }
        }
    }
}