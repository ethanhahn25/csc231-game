#pragma once
#include <memory>
//forward declare variable
class Entity;
class Engine;
class Action;

namespace Heros {

    void make_wizard(std::shared_ptr<Entity> entity);

    std::unique_ptr<Action> behavior(Engine& engine, Entity& entity);
}
