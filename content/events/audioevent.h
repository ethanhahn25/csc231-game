#pragma once

#include "event.h"
#include <string>

class AudioEvent : public Event {
public:
    AudioEvent(const std::string& name);
    void execute(Engine& engine) override;
private:
    std::string name;
};

