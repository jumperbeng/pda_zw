
cmake_minimum_required(VERSION 2.8)
 
PROJECT(local_vis)
 
find_package(VTK REQUIRED)
include(${VTK_USE_FILE}) 
include_directories("/home/jumper/Documents/PDA/limbo/include")

add_executable(local_vis MACOSX_BUNDLE main.cpp data_structure.cpp )
 
target_link_libraries(local_vis ${VTK_LIBRARIES} "/home/jumper/Documents/PDA/limbo/lib/liblefparseradapt.a" "/home/jumper/Documents/PDA/limbo/lib/libdefparseradapt.a")
