cmake_minimum_required(VERSION 2.8)

project(hexsimple)
set(CMAKE_CXX_COMPILER /usr/bin/g++)

# enable c++11 support
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11 -Wall")
if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(--std=c++11)
endif()

include_directories(include)
file(GLOB SOURCES
    include/*.h
    src/*.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
