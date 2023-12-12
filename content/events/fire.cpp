#include "fire.h"
#include "hit.h"
#include "engine.h"
#include "audioevent.h"

Fire::Fire(Vec position)
    : position{position} {}

void Fire::execute(Engine& engine) {
    if(frame_count == 0){
        sprite = engine.graphics.get_animated_sprite("fire");
        number_of_frames = sprite.number_of_frames();
        engine.events.create_event<AudioEvent>("fire");
    }
    engine.camera.add_overlay(position, sprite.get_sprite());
    sprite.update();
}

void Fire::when_done(Engine& engine) {
    Tile& tile = engine.dungeon.get_tile(position);
    if(tile.has_entity()){
        Entity& entity = *tile.entity;
        engine.events.create_event<Hit>(entity, damage);
    }
}