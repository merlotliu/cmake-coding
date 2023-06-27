# set cmake minimum version required
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# set project name & version number
PROJECT(LuMath)
SET(PROJECT_VERSION_MAJOR 1)
SET(PROJECT_VERSION_MINOR 0)

# set output path of dynamic library
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

# set output path of static library
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

# set output path of executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# add include path 
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

# find source files
AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/src SRC_LIST)

# create static library
ADD_LIBRARY(${PROJECT_NAME}a STATIC ${SRC_LIST})

# change target name ${PROJECT_NAME}a ==> ${PROJECT_NAME}
SET_TARGET_PROPERTIES(${PROJECT_NAME}a PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

# avoid CMake clean the same name of target
SET_TARGET_PROPERTIES(${PROJECT_NAME}a PROPERTIES CLEAN_DIRECT_OUTPUT 1)

# create dynamic library
ADD_LIBRARY(${PROJECT_NAME} SHARED ${SRC_LIST})

# set dynamic library & API version number
SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES 
    VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR} 
    SOVERSION ${PROJECT_VERSION_MAJOR}
)

# create executable
ADD_EXECUTABLE(add main.cpp)

# link dynamic libraries
target_link_libraries(add ${PROJECT_NAME})