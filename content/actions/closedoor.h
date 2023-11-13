#include "action.h"

class Closedoor : public Action {
public:
    Result perform(Engine& engine, std::shared_ptr<Entity> entity) override;
};