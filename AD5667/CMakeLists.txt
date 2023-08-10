add_library(AD5667 STATIC AD5667.hpp AD5667.cpp)
target_include_directories(AD5667 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(AD5667 GPIO etl)
message("Added AD5667 lib")