cmake_minimum_required(VERSION 3.20)
project(adventofcode
        VERSION 0.1.0
        DESCRIPTION "Advent of Code 2024"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_WITH_INSTALL_NAME_DIR ON)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "-Wshadow -Wall -Wextra -pedantic -Wconversion   -fsanitize=address,undefined")
set(CMAKE_CXX_FLAGS_DEBUG "-g -pthread")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

# copy input
file(COPY ${PROJECT_SOURCE_DIR}/input DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${PROJECT_SOURCE_DIR}/test DESTINATION ${CMAKE_BINARY_DIR})

add_executable(day1 src/day1.cpp)
#[[ target_sources(day1 PRIVATE
	${PROJECT_SOURCE_DIR}/include/day1.h
	${PROJECT_SOURCE_DIR}/include/doctest.h
) ]]
target_include_directories(day1 PRIVATE ${PROJECT_SOURCE_DIR}/include)

add_executable(day2 src/day2.cpp)
target_include_directories(day2 PRIVATE ${PROJECT_SOURCE_DIR}/include)
#[[ target_sources(day2
	PRIVATE
	${PROJECT_SOURCE_DIR}/include/day2.h
	${PROJECT_SOURCE_DIR}/include/.h
) ]]

