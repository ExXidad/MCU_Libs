add_library(Timer STATIC Timer.cpp Timer.hpp)
target_include_directories(Timer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
message("Added Timer lib")