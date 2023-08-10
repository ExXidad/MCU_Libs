add_library(GPIO INTERFACE)
target_include_directories(GPIO INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
message("Added GPIO lib")