cmake_minimum_required(VERSION 3.5.0)
project(Text_RPG VERSION 0.1.0 LANGUAGES C CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(Text_RPG/include)

file(GLOB SOURCES "Text_RPG/src/*.cpp")

add_executable(Text_RPG "Text_RPG/main.cpp" ${SOURCES})