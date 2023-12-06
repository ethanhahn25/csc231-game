#include "mace.h"
#include "hit.h"
#include "engine.h"
#include "thrust.h"
#include "events.h"
#include "swing.h"
#include "audioevent.h"

Mace::Mace(int damage)
    :Weapon{"mace", damage}{}

void Mace::use(Engine& engine, Entity& attacker, Entity& defender){
    Vec direction = defender.get_position() - attacker.get_position();
    std::shared_ptr<Event> swing = engine.events.create_event<Swing>(sprite, direction);
    swing->add_next(Hit{defender, damage});
    engine.events.create_event<AudioEvent>("metal-clang");
}