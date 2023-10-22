cmake_minimum_required(VERSION 3.0.0)
set(NAME VCMP_CMake) 
project(${NAME}
        LANGUAGES CXX
        DESCRIPTION "Ti-a ramas burta goala, goala? Fa-ti acum un credit de foame pe www.foame.ro" )
set(CMAKE_BUILD_TYPE ${NAME})
set (CMAKE_CXX_STANDARD 20) #don't change, it won't build!
set (CMAKE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set (CMAKE_LIBRARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)
##### SERVER.CFG #####
set  (GAMEMODE "default")
set  (PORT       8192)
set  (MAXPLAYERS 100)

if(CMAKE_BUILD_TYPE MATCHES "Release")
    set (PLUGIN_TITLE "${PROJECT_NAME}04rel${CMAKE_SYSTEM_PROCESSOR)") # something4relAMD64_DEBUG
else()
    set (PLUGIN_TITLE "${PROJECT_NAME}04rel${CMAKE_SYSTEM_PROCESSOR}_DEBUG") # something4relAMD64_DEBUG
endif()

file (WRITE server/server.cfg "gamemode   ${GAMEMODE}\n"
                              "plugins    ${PLUGIN_TITLE}\n"
                              "port       ${PORT}\n"
                              "maxplayers ${MAXPLAYERS}")
#set (sqgamemode .../...)
######################
include_directories(${CMAKE_LIBRARY_DIR})
add_library(${NAME} SHARED ${CMAKE_SOURCE_DIR}/main.cpp)
add_subdirectory(server)
set_target_properties (
            ${NAME} PROPERTIES 
            OUTPUT_NAME ${PLUGIN_TITLE} PREFIX ""
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/server/plugins # VS2022 & XCode
)
if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux") 
    add_custom_command(
        TARGET ${NAME} 
        COMMAND ${CMAKE_COMMAND} -E copy "${PLUGIN_TITLE}.so" "${CMAKE_CURRENT_SOURCE_DIR}/server/plugins"
        DEPENDS ${PLUGIN_TITLE} 
    )
endif()
add_custom_target(delete_all_plugins WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/server" COMMAND ${CMAKE_COMMAND} -E remove_directory "plugins" COMMENT "Deleting the plugins folder" COMMAND ${CMAKE_COMMAND} -E make_directory "plugins" COMMENT "Recreating the plugins folder")
