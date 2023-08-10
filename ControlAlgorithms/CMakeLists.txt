add_library(ControlAlgorithms INTERFACE)
target_include_directories(ControlAlgorithms INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
message("Added FeedbackControl lib")