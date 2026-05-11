cmake_minimum_required(VERSION 3.10)

project(mnist)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

set(EIGEN3_INCLUDE_DIR "/usr/local/include/eigen3")

set(PROJECT_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

add_executable(${PROJECT_NAME} main.cpp helpers.cpp) 

target_include_directories(${PROJECT_NAME} PRIVATE 
    ${EIGEN3_INCLUDE_DIR}
    ${PROJECT_INCLUDE_DIR}
)
