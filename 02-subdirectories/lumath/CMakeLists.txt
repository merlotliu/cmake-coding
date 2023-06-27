# set project name
PROJECT(LuMath)

# add include path 
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

# find source files
AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/src SRC_LIST)

# create static library
ADD_LIBRARY(${PROJECT_NAME} ${SRC_LIST})
