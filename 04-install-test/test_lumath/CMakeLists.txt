# set cmake minimum version required
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# set project name
PROJECT(TestLuMath)

# create executable
ADD_EXECUTABLE(Add main.cpp)

# link lumath lib
TARGET_LINK_LIBRARIES(Add libLuMath.so)

# enable ctest
ENABLE_TESTING()

# test running
ADD_TEST(NAME Runs COMMAND Add 11 22)

# test usage
ADD_TEST(NAME Usage COMMAND Add)
SET_TESTS_PROPERTIES(Usage
    PROPERTIES PASS_REGULAR_EXPRESSION "usage : Add a b"
)

# test standard use
ADD_TEST(NAME StandardUse COMMAND Add 6 1)
SET_TESTS_PROPERTIES(StandardUse
    PROPERTIES PASS_REGULAR_EXPRESSION "= 7"
)

# make macro for test case
FUNCTION(do_test arg1 arg2 result)
ADD_TEST(NAME Add_${arg1}_${arg2} COMMAND Add ${arg1} ${arg2})
SET_TESTS_PROPERTIES(Add_${arg1}_${arg2}
    PROPERTIES PASS_REGULAR_EXPRESSION "= ${result}"
)
ENDFUNCTION()

# do a bunch of result based tests
do_test(11 22 33)
do_test(-33 66 33)
do_test(-123 -456 -579)
