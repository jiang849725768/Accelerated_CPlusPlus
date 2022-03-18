cmake_minimum_required(VERSION 3.1)

#工程名字定义
PROJECT(chapter_four)

# 编程标准设定（C++20）
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#定义工程包含的文件夹及文件
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#main
set(PROJECT_MAIN_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
file(GLOB project_main_source_files ${PROJECT_MAIN_DIR}/*.cpp)
source_group("Source Files" FILES ${project_main_source_files})

#algorithm
set(PROJECT_ALGORITHM_DIR "${PROJECT_MAIN_DIR}/algorithm")
file(GLOB project_algorithm_header_files ${PROJECT_ALGORITHM_DIR}/*.h)
file(GLOB project_algorithm_source_files ${PROJECT_ALGORITHM_DIR}/*.cpp)
source_group("Header Files\\algorithm" FILES ${project_algorithm_header_files})
source_group("Source Files\\algorithm" FILES ${project_algorithm_source_files})

#将上述文件夹include进工程
include_directories(${PROJECT_MAIN_DIR} 
                    ${PROJECT_ALGORITHM_DIR})

#定义程序所用文件
add_executable(${PROJECT_NAME}
               ${project_main_source_files}
               ${project_algorithm_header_files}
               ${project_algorithm_source_files})


#文件输出路径
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

#生成程序放置位置
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)