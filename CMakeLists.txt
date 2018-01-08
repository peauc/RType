cmake_minimum_required(VERSION 3.5)
project(r-type)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCE_FILES
        "src/*.cpp"
        "include/*.hpp")

include_directories(include)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
