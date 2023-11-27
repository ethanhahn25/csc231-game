add_library(weapons
  bite.cpp
        staff.cpp
        staff.h
        mace.cpp
        mace.h
        bow.cpp
        bow.h
)

target_include_directories(weapons PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(weapons PUBLIC engine events)
