cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
include(files.cmake)

conan_set_find_paths()

project(advent_of_code2019)

find_package(Boost)
find_package(cereal)

add_library(
  utils SHARED
  ${UTIL_SRCS}
)

target_include_directories(
  utils
  PUBLIC ${Boost_INCLUDE_DIR}
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(
  utils
  ${Boost_LIBRARIES}
)

add_executable(
  day1
  ${DAY1_SRCS}
)

target_link_libraries(
  day1
  utils
  cereal
)

add_executable(
  day2
  ${DAY2_SRCS}
)

target_link_libraries(
  day2
  ic
  cereal
)

add_executable(
  day5
  ${DAY5_SRCS}
)

target_link_libraries(
  day5
  ic
  cereal
)

add_executable(
  day6
  ${DAY6_SRCS}
)

target_link_libraries(
  day6
  utils
  cereal
)

add_executable(
  day7
  ${DAY7_SRCS}
)

target_link_libraries(
  day7
  ic
  cereal
)

add_executable(
  day8
  ${DAY8_SRCS}
)

target_link_libraries(
  day8
  utils
  cereal
)

add_executable(
  day9
  ${DAY9_SRCS}
)

target_link_libraries(
  day9
  ic
  cereal
)

add_executable(
  day10
  ${DAY10_SRCS}
)

target_link_libraries(
  day10
  cereal
)

add_library(
  ic SHARED
  ${IC_SRCS}
)

target_include_directories(
  ic 
  PUBLIC ${CMAKE_SOURCE_DIR}/intcode_computer/
)