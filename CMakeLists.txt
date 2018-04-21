cmake_minimum_required(VERSION 3.9.6)
project(myls)

set(CMAKE_CXX_STANDARD 14)
find_package(Boost COMPONENTS program_options filesystem REQUIRED)
include_directories( ${Boost_INCLUDE_DIRS} )

add_executable(myls main.cpp UserChoise.cpp UserChoise.h SortAlgorithms.cpp SortAlgorithms.h Sorter.cpp Sorter.h Typedefs.h)
target_link_libraries(myls ${Boost_LIBRARIES})