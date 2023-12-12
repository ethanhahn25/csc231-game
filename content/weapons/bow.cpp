#include "bow.h"
#include "hit.h"
#include "engine.h"
#include "thrust.h"
#include "events.h"
#include "lightning.h"

Bow::Bow(int damage)
    :Weapon{"bow", damage}{}

void Bow::use(Engine& engine, Entity& attacker, Entity& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    std::shared_ptr<Event> thrust = engine.events.create_event<Thrust>(sprite, direction);
    std::shared_ptr<Event> lightning = std::make_shared<Lightning>(defender.get_position());
    thrust->add_next(lightning);
}