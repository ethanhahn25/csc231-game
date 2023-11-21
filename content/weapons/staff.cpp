#include "staff.h"

#include "hit.h"

#include "engine.h"

Staff::Staff(int damage)
    :Weapon{"staff_red", damage}{}

void Staff::use(Engine& engine, Entity&, Entity& defender){
    engine.events.create_event<Hit>(defender, damage);
}