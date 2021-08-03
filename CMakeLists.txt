cmake_minimum_required(VERSION 3.8)

set(this httpproject)

project(${this})

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)


set(source
        source/Parser.cpp
    )
include_directories(${this} include)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_library(${this} ${source})

# Link runTests with what we want to test and the GTest and pthread library
target_link_libraries(${this} 
                        ${GTEST_BOTH_LIBRARIES}
                        pthread
                        )

add_test(
    NAME ${this}
    COMMAND ${this}
)
add_subdirectory(tests)