#include "rest.h"
#include <iostream>

Result Rest::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    std::cout << "Resting...\n";
    return success();
}
