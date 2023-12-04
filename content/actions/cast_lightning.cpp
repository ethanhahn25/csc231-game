#include "cast_lightning.h"
#include "randomness.h"
#include "entity.h"
#include "engine.h"
#include "lightning.h"

Result CastLightning::perform(Engine& engine, std::shared_ptr<Entity> entity){
    auto [px, py] = entity->get_position();
    while(true) {
        int x = randint(px - 5., px + 5);
        int y = randint(py - 5, py + 5);
        if(engine.dungeon.tiles.within_bounds({x, y})){
            px = x;
            py = y;
            break;
        }
    }
        engine.events.create_event<Lightning>(Vec{px, py});
        return success();

}