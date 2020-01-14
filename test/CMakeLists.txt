include_directories(../src)
include_directories(${PROJECT_SOURCE_DIR}/test)
add_executable(${PROJECT_NAME} testdefault.cpp ../src/life.cpp Arduino.cpp testrandom.cpp)
target_link_libraries(${PROJECT_NAME} gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
