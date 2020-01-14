include_directories(../src)
include_directories(${PROJECT_SOURCE_DIR}/test)
add_executable(${PROJECT_NAME} 
    ../src/life.cpp 
    Arduino.cpp 
    testrandom.cpp
    testrules.cpp
    testdefault.cpp 
    )
target_link_libraries(${PROJECT_NAME} gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
