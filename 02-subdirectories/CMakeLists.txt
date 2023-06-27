# set cmake minimum version required
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# set project name
PROJECT(SubDir)

# add subdirectory
ADD_SUBDIRECTORY(lumath)

# add include path 
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/lumath/include)

# create executable
ADD_EXECUTABLE(add main.cpp)

# link dynamic libraries
target_link_libraries(add LuMath)