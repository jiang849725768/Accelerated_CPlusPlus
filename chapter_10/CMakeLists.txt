cmake_minimum_required(VERSION 3.4)

#工程名字定义
PROJECT(chapter_ten)
message(${PROJECT_SOURCE_DIR})

# 编程标准设定（C++17）
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

# main
set(PROJECT_MAIN_DIR "${PROJECT_SOURCE_DIR}/source")
file(GLOB main_file ${PROJECT_MAIN_DIR}/main.cpp)
source_group("Source" FILES ${main_file})

# include
set(PROJECT_HEADER_DIR "${PROJECT_SOURCE_DIR}/include")
file(GLOB algorithm_header_files ${PROJECT_HEADER_DIR}/*.h)
source_group("Include" FILES ${algorithm_header_files})

# algorithm
set(PROJECT_ALGORITHM_DIR "${PROJECT_SOURCE_DIR}/source/algorithm")
file(GLOB algorithm_source_files ${PROJECT_ALGORITHM_DIR}/*.cpp)
source_group("Source\\algorithm" FILES ${algorithm_source_files})

# 将文件include进工程
# target_include_directories( ${PROJECT_NAME} PRIVATE ${PROJECT_HEADER_DIR})
include_directories(${PROJECT_HEADER_DIR})

#定义程序所用文件
add_executable(${PROJECT_NAME}
               ${main_file}
               ${algorithm_header_files}
               ${algorithm_source_files})


#文件工作路径
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}")

#生成程序放置位置
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)