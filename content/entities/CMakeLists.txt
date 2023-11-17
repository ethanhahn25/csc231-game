add_library(entities
  heros.cpp
  monsters.cpp
        wander.cpp
        wander.h
)

target_include_directories(entities PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(entities PUBLIC engine actions weapons)
