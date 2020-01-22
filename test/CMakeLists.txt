include_directories(../src)
include_directories(${PROJECT_SOURCE_DIR}/test)
add_executable(${PROJECT_NAME} 
    ../src/rules.cpp 
    ../src/board.cpp 
    ../src/game.cpp 
    ../src/matrixAdapter.cpp
    Arduino.cpp 
    testgame.cpp
    testrandom.cpp
    testrules.cpp
    testboard.cpp
    testneighbors.cpp
    mockMatrixAdapter.cpp
    )
target_link_libraries(${PROJECT_NAME} gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
