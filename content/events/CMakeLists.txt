add_library(events
  updatefov.cpp
        hit.cpp
        hit.h
        die.cpp
        die.h
        thrust.cpp
        thrust.h
        swing.cpp
        swing.h
        lightning.cpp
        lightning.h
        audioevent.cpp
        audioevent.h
        fire.cpp
        fire.h
        fireball.cpp
        fireball.h
)

target_include_directories(events PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(events PUBLIC engine)
