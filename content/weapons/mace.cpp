#include "mace.h"
#include "hit.h"
#include "engine.h"
#include "thrust.h"
#include "events.h"

Mace::Mace(int damage)
    :Weapon{"mace", damage}{}

void Mace::use(Engine& engine, Entity& attacker, Entity& defender){
    Vec direction = defender.get_position() - attacker.get_position();
    std::shared_ptr<Event> thrust = engine.events.create_event<Thrust>(sprite, direction);
    thrust->add_next(Hit{defender, damage});
}