cmake_minimum_required(VERSION 2.4)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(cpp/ciagi)


include_directories(cpp/include)
file(GLOB SOURCES "cpp/src/*.cpp")
add_executable(ciagi ${SOURCES})
