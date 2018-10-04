cmake_minimum_required(VERSION 3.9)
project(shifumi)

set(CMAKE_CXX_STANDARD 14)

add_executable(shifumi main.cpp std_lib_facilities.h termcolor.hpp player_vs_ai_module.cpp player_vs_ai_module.h TSS.cpp TSS.h)