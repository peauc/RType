cmake_minimum_required(VERSION 3.2)
project(rtype)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

file(GLOB_RECURSE SERVER_SRC server/src/*.cpp)
file(GLOB_RECURSE SERVER_INC server/inc/*.hpp)
set(SERVER_FILES ${SERVER_SRC} ${SERVER_INC})
include_directories(server/inc)
add_executable(server ${SERVER_FILES})

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


##SMFL
set(CMAKE_MODULE_PATH "${CMAKE_HOME_DIRECTORY}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(server ${SFML_LIBRARIES})
endif()
