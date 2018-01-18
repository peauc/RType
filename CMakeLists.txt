cmake_minimum_required(VERSION 3.2)
project(rtype)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")

##COMMON
file(GLOB_RECURSE COMMON_FILES common/*.cpp common/*.hpp)
include_directories(common/inc)

##SERVER

file(GLOB_RECURSE SERVER_SRC server/src/*.cpp RessourcesLoader/sources/*.cpp)
file(GLOB_RECURSE SERVER_INC server/inc/*.hpp RessourcesLoader/includes/*.hpp)
set(SERVER_FILES ${SERVER_SRC} ${SERVER_INC})
include_directories(server/inc)
add_executable(server ${SERVER_FILES} ${COMMON_FILES})

##BOOST
if (WIN32)
    set(BOOST_ROOT "C:\\boost_1_65_1")
    set(BOOST_LIBRARYDIR ${BOOST_ROOT}/stage/lib/)
endif (WIN32)
set(Boost_USE_STATIC_LIBS        ON)
find_package(Boost REQUIRED COMPONENTS system thread filesystem regex serialization)
include_directories( ${Boost_INCLUDE_DIRS} )
target_link_libraries(server
        ${Boost_LOG_SETUP_LIBRARY}
        ${Boost_LOG_LIBRARY}
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_THREAD_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_SERIALIZATION_LIBRARY}
        )

##CLIENT

file(GLOB_RECURSE CLIENT_SRC client/src/*.cpp)
file(GLOB_RECURSE CLIENT_INC client/inc/*.hpp)
set(CLIENT_FILES ${CLIENT_SRC} ${CLIENT_INC})
include_directories(client/inc)
add_executable(client ${CLIENT_FILES} ${COMMON_FILES})

##BOOST
if (WIN32)
    set(BOOST_ROOT "C:\\boost_1_65_1")
    set(BOOST_LIBRARYDIR ${BOOST_ROOT}/stage/lib/)
endif (WIN32)
set(Boost_USE_STATIC_LIBS        ON)
find_package(Boost REQUIRED COMPONENTS system thread filesystem regex serialization)
include_directories( ${Boost_INCLUDE_DIRS} )
target_link_libraries(client
        ${Boost_LOG_SETUP_LIBRARY}
        ${Boost_LOG_LIBRARY}
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_THREAD_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_SERIALIZATION_LIBRARY}
        )


##SMFL
set(CMAKE_MODULE_PATH "${CMAKE_HOME_DIRECTORY}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(client ${SFML_LIBRARIES})
endif()
