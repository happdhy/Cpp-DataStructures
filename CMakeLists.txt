cmake_minimum_required(VERSION 3.10)

# 项目名字
project(DataStructure_Learning)

# 设置C++标准为 C++17
set(CMAKE_CXX_STANDARD 17)

# 告诉编译器头文件去 include 文件夹里找
include_directories(include)

# 自动发现 src 目录下的所有 .cpp 文件，存入 SOURCES 变量
file(GLOB SOURCES "src/*.cpp")

# 生成可执行文件，名字叫 main_app
add_executable(main_app ${SOURCES})