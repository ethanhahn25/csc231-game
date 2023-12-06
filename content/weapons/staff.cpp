#include "staff.h"
#include "hit.h"
#include "engine.h"
#include "thrust.h"
#include "events.h"
#include "swing.h"
#include "lightning.h"
#include "audioevent.h"

Staff::Staff(int damage)
    :Weapon{"staff_red", damage}{}

void Staff::use(Engine& engine, Entity& attacker, Entity& defender){
    Vec direction = defender.get_position() - attacker.get_position();
    std::shared_ptr<Event> thrust = engine.events.create_event<Thrust>(sprite, direction);
    std::shared_ptr<Event> lightning = std::make_shared<Lightning>(defender.get_position());
    thrust->add_next(lightning); //via pointer
}