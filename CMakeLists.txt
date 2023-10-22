cmake_minimum_required(VERSION 3.0.0)
project(VCMP-CMake
        LANGUAGES CXX 
        DESCRIPTION "Ti-a ramas burta goala, goala? Fa-ti acum un credit de foame pe www.foame.ro" )

set (CMAKE_CXX_STANDARD 20) #don't change, it won't build!
set (CMAKE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set (CMAKE_LIBRARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)
##### SERVER.CFG #####
set  (GAMEMODE "default")
if(CMAKE_BUILD_TYPE MATCHES "Release")
    set (PLUGIN_TITLE "${PROJECT_NAME}04rel${CMAKE_HOST_SYSTEM_PROCESSOR)") # VCMP-CMake4relAMD64_DEBUG
else()
    set (PLUGIN_TITLE "${PROJECT_NAME}04rel${CMAKE_HOST_SYSTEM_PROCESSOR}_DEBUG") # VCMP-CMake4relAMD64_DEBUG
endif()
set  (PORT       8192)
set  (MAXPLAYERS 100)
file (WRITE server/server.cfg "gamemode   ${GAMEMODE}\n"
                              "plugins    ${PLUGIN_TITLE}\n"
                              "port       ${PORT}\n"
                              "maxplayers ${MAXPLAYERS}")
#set (sqgamemode .../...)
######################
include_directories(${CMAKE_LIBRARY_DIR})
add_library(VCMP-CMake SHARED ${CMAKE_SOURCE_DIR}/main.cpp)
#add_subdirectory(server)
if (UNIX) 
    add_custom_command(
        TARGET VCMP-CMake
        COMMAND ${CMAKE_COMMAND} -E copy "${PLUGIN_TITLE}.so" ${CMAKE_CURRENT_SOURCE_DIR}/server/plugins
        DEPENDS ${PLUGIN_TITLE}
    )
endif()

set_target_properties (
    VCMP-CMake PROPERTIES 
    OUTPUT_NAME ${PLUGIN_TITLE} PREFIX ""
    CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR}/server/plugins # VS2022 & XCode
)