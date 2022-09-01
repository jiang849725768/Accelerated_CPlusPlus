cmake_minimum_required(VERSION 3.1)

#工程名字定义
PROJECT(chapter_sixteen)

# 编程标准设定（C++17）
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# main
file(GLOB main_file ${PROJECT_SOURCE_DIR}/src/main.cpp)
source_group("Source" FILES ${main_file})

# include
set(PROJECT_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/src/algorithm")
file(GLOB algorithm_header_files ${PROJECT_INCLUDE_DIR}/*.h)
source_group("Include" FILES ${algorithm_header_files})

# source
set(PROJECT_ALGORITHM_DIR "${PROJECT_SOURCE_DIR}/src/algorithm")
file(GLOB algorithm_source_files ${PROJECT_ALGORITHM_DIR}/*.cpp)
source_group("Source\\algorithm" FILES ${algorithm_source_files})

# 将头文件include进工程
include_directories(${PROJECT_INCLUDE_DIR})

#定义程序所用文件
add_executable(${PROJECT_NAME}
               ${main_file}
               ${algorithm_header_files}
               ${algorithm_source_files})


#工作路径
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

#生成程序放置位置
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)