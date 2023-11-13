#include "heros.h"
#include "entity.h"
#include "engine.h"
#include "Move.h"
#include "rest.h"
#include "closedoor.h"

namespace Heros {

    void make_wizard(std::shared_ptr<Entity> entity){
        entity->set_sprite("wizard");
        entity->behavior = behavior;
    }
    std::unique_ptr<Action> behavior(Engine& engine, Entity& entity){
        std::string key = engine.input.get_last_keypress();
        if(key == "R") {
            return std::make_unique<Rest>();
        }
        else if(key =="C"){
            return std::make_unique<Closedoor>();
        }
        else if(key =="W"){
            return std::make_unique<Move>(Vec{0,1});
        }
        else if(key =="A"){
            return std::make_unique<Move>(Vec{-1,0});
        }
        else if(key =="S"){
            return std::make_unique<Move>(Vec{0,-1});
        }
        else if(key =="D"){
            return std::make_unique<Move>(Vec{1,0});
        }

        return nullptr;
    }
}
