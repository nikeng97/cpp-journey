cmake_minimum_required(VERSION 3.10)

project(CppStdWalkThrough LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fconcepts -Wall")

file(GLOB SOURCE_FILES src/*.cpp)

foreach(SOURCE_FILE ${SOURCE_FILES})
    get_filename_component(EXEC_NAME ${SOURCE_FILE} NAME_WE)
    add_executable(${EXEC_NAME} ${SOURCE_FILE})
endforeach()