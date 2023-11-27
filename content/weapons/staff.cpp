#include "staff.h"

#include "hit.h"

#include "engine.h"

#include "thrust.h"

#include "events.h"

Staff::Staff(int damage)
    :Weapon{"staff_red", damage}{}

void Staff::use(Engine& engine, Entity& attacker, Entity& defender){
    Vec direction = defender.get_position() - attacker.get_position();
    std::shared_ptr<Event> thrust = engine.events.create_event<Thrust>(sprite, direction);
    thrust->add_next(Hit{defender, damage});
}