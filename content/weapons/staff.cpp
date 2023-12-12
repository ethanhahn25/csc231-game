#include "staff.h"

#include <cmath>

#include "audioevent.h"
#include "engine.h"
#include "events.h"
#include "fireball.h"
#include "hit.h"
#include "lightning.h"
#include "swing.h"
#include "thrust.h"

Staff::Staff(int damage) : Weapon{"staff_red", damage} {}

void Staff::use(Engine& engine, Entity& attacker, Entity& defender) {
    Vec distance = defender.get_position() - attacker.get_position();
    if (abs(distance.x) == 1 || abs(distance.y) == 1) {
        std::shared_ptr<Event> thrust = engine.events.create_event<Thrust>(sprite, distance);
        // std::shared_ptr<Event> hit = engine.events.create_event<Hit>(defender, damage);
        thrust->add_next(Hit{defender, damage});
    } else {
        std::shared_ptr<Event> fireball =
            engine.events.create_event<Fireball>(sprite, attacker.get_direction(), damage,
                                                 attacker.get_position(), defender.get_position());
        // std::shared_ptr<Event> hit = engine.events.create_event<Hit>(defender, damage);
        fireball->add_next(Hit{defender, damage});
    }
}