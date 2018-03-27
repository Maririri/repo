cmake_minimum_required(VERSION 2.8)
project(STLTemplates-1)

add_definitions(-std=c++11)

add_subdirectory(includes)
add_subdirectory(subdir2)

# To find path to includes
include_directories(${STLTemplates-1_SOURCE_DIR}/includes)

add_executable(myBinary mystl)

target_link_libraries(myBinary myLib)