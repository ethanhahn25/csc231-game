#include "attack.h"
#include "entity.h"
#include "action.h"
#include "weapon.h"

Attack::Attack(Entity& defender)
    :defender{defender} {}

Result Attack::perform(Engine& engine, std::shared_ptr<Entity> attacker){
    std::shared_ptr<Weapon> weapon = attacker->get_weapon();
    weapon->use(engine, *attacker, defender);
    return success();
}