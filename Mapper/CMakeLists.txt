cmake_minimum_required(VERSION 3.2)
project(Mapper)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/..)

include_directories(includes)

file(GLOB SOURCE_FILES
        "sources/*.cpp"
        "includes/*.hpp")
add_executable(Mapper ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_HOME_DIRECTORY}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Mapper ${SFML_LIBRARIES})
endif()
