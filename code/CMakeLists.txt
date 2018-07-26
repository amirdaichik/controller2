cmake_minimum_required(VERSION 3.12)
project(project)

set(CMAKE_CXX_STANDARD 11)

add_executable(project main.cpp block.cpp block.h picture.cpp picture.h serial_cluster_block.cpp serial_cluster_block.h referenceBlock.cpp referenceBlock.h screen.cpp screen.h)