cmake_minimum_required(VERSION 3.10)

# Project name
project(CS260_theEngineer)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable (list all .cpp files)
add_executable(CS260_theEngineer
    main.cpp
    theEngineer.cpp
    theEngineerList.cpp

)

add_custom_command(TARGET CS260_theEngineer POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/theEngineer.txt
        $<TARGET_FILE_DIR:CS260_theEngineer>/theEngineer.txt
    COMMENT "Copying theEngineer.txt to build directory"
)
