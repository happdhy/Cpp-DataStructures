cmake_minimum_required(VERSION 3.10)
project(DataStructure_Learning)

set(CMAKE_CXX_STANDARD 17)

# 包含头文件目录 (让所有cpp都能找到 include 里的 .hpp)
include_directories(include)



add_executable(test_list src/MyLinkedList.cpp)