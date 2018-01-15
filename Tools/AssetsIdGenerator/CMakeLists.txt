cmake_minimum_required(VERSION 3.7)
project(AssetsIdGenerator)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/..)

include_directories(includes)

file(GLOB SOURCE_FILES
        "sources/*.cpp"
        "includes/*.hpp")

add_executable(AssetsIdGenerator ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_HOME_DIRECTORY}/cmake_modules")
find_package(Boost COMPONENTS system filesystem REQUIRED)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(AssetsIdGenerator ${Boost_LIBRARIES})
endif()
