# set cmake minimum version required
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# set project name
PROJECT(01Basic)

MESSAGE(STATUS "Configuring begin")

MESSAGE(STATUS ${PROJECT_SOURCE_DIR})

MESSAGE(STATUS ${PROJECT_BINARY_DIR})

# create executable
ADD_EXECUTABLE(${PROJECT_NAME} 
    main.cpp
)