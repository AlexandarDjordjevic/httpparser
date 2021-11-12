cmake_minimum_required(VERSION 3.8)

set(this http)

project(${this})

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)


set(source
        source/Request.cpp
        source/Message.cpp
        source/Response.cpp
    )

add_subdirectory(external/Uri)

add_library(${this} STATIC ${source})

target_include_directories(${this} PUBLIC include)

target_link_libraries(${this} uri)

add_subdirectory(tests)