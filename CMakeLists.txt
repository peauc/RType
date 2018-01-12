cmake_minimum_required(VERSION 3.2)
project(rtype)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

file(GLOB_RECURSE SERVER_SRC server/src/*.cpp)
file(GLOB_RECURSE SERVER_INC server/inc/*.hpp)
set(SERVER_FILES ${SERVER_SRC} ${SERVER_INC})
add_executable(server ${SERVER_FILES})

include_directories(server/inc)
set(CMAKE_MODULE_PATH "${CMAKE_HOME_DIRECTORY}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(server ${SFML_LIBRARIES})
endif()
