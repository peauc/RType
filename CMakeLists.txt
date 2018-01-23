cmake_minimum_required(VERSION 3.2)
project(rtype)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -W -Wall -Wextra -Werror")
if (LINUX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

endif(LINUX)
##COMMON
file(GLOB_RECURSE COMMON_FILES common/*.cpp common/*.hpp
        common/ResourcesLoader/inc/*.hpp
        common/ResourcesLoader/sources/*.cpp
        common/JsonLoader/includes/*.hpp
        common/JsonLoader/sources/*.cpp)
include_directories(common/inc
        common/ResourcesLoader/inc
        common/JsonLoader/includes
        server/inc
        server/inc/Engine/
        server/inc/Common
        server/inc/MapLoader
        server/inc/Components
        server/inc/Components/Abstracts/
        server/inc/Components/Camera
        server/inc/Components/Player
        server/inc/Components/Projectiles
        server/inc/Components/Zone
        server/inc/Factories
        server/inc/Engine/Commands
        client/inc)

##TOOL

include_directories(Tools/AssetsIdGenerator/includes)
include_directories(Tools/common/includes)

file(GLOB_RECURSE TOOL_FILES
        "Tools/AssetsIdGenerator/sources/*.cpp"
        "Tools/AssetsIdGenerator/includes/*.hpp"
        "Tools/common/includes/*.hpp"
        "Tools/common/sources/*.cpp")

add_executable(AssetsIdGenerator ${TOOL_FILES} ${COMMON_FILES})


##SERVER

file(GLOB_RECURSE SERVER_SRC server/src/*.cpp)
file(GLOB_RECURSE SERVER_INC server/inc/*.hpp)
set(SERVER_FILES ${SERVER_SRC} ${SERVER_INC})
add_executable(server ${COMMON_FILES} ${SERVER_FILES})

##CLIENT

file(GLOB_RECURSE CLIENT_SRC client/src/*.cpp)
file(GLOB_RECURSE CLIENT_INC client/inc/*.hpp)
set(CLIENT_FILES ${CLIENT_SRC} ${CLIENT_INC})
add_executable(client ${COMMON_FILES} ${CLIENT_FILES})

##BOOST
if (WIN32)
    set(BOOST_ROOT "C:\\boost_1_65_1")
    set(BOOST_LIBRARYDIR ${BOOST_ROOT}/stage/lib/)
endif (WIN32)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED COMPONENTS system thread filesystem regex serialization)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(client
        ${Boost_LOG_SETUP_LIBRARY}
        ${Boost_LOG_LIBRARY}
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_THREAD_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_SERIALIZATION_LIBRARY}
        )
target_link_libraries(AssetsIdGenerator
        ${Boost_LOG_SETUP_LIBRARY}
        ${Boost_LOG_LIBRARY}
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_THREAD_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_SERIALIZATION_LIBRARY}
        )
target_link_libraries(server
        ${Boost_LOG_SETUP_LIBRARY}
        ${Boost_LOG_LIBRARY}
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_THREAD_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_SERIALIZATION_LIBRARY}
        -ldl
        )


##SMFL
set(CMAKE_MODULE_PATH "${CMAKE_HOME_DIRECTORY}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(client ${SFML_LIBRARIES})
endif ()
