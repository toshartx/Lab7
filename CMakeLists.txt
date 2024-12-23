cmake_minimum_required(VERSION 3.20)
project(Lab6)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_COMPILER /usr/bin/clang++)
set(CMAKE_C_COMPILER /usr/bin/clang)

# Санитайзер
set(SAN "thread")
add_compile_options("-fsanitize=${SAN}")
add_link_options("-fsanitize=${SAN}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/exe)

include_directories(${PROJECT_SOURCE_DIR}/include)
#include_directories(${PROJECT_SOURCE_DIR}/../Libs/headers)

#add_library(UsefulLib STATIC ../Libs/src/UsefulLib.cpp)
add_library(Task_1 STATIC src/Task_1/Task_1.cpp)
add_library(Task_2 STATIC src/Task_2/Task_2.cpp)
add_library(Task_3 STATIC src/Task_3/Task_3.cpp)
add_library(Task_4 STATIC src/Task_4/Task_4.cpp)
add_library(Task_5 STATIC src/Task_5/Task_5.cpp)
add_library(MainFuncs STATIC src/MainFuncs.cpp)

# target_link_libraries(solve PRIVATE UsefulLib)
add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE MainFuncs)
target_link_libraries(MainFuncs PRIVATE Task_1)
target_link_libraries(MainFuncs PRIVATE Task_2)
target_link_libraries(MainFuncs PRIVATE Task_3)
target_link_libraries(MainFuncs PRIVATE Task_4)
target_link_libraries(MainFuncs PRIVATE Task_5)