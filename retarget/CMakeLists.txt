add_library(retarget STATIC retarget.c retarget.h)
target_include_directories(retarget PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
message("Added retarget lib")