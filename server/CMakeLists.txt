project (runserver)
if(("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "x86_64" OR "${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "AMD64") AND "${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
    add_custom_target(64bit_windows ALL DEPENDS ${NAME} WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
    add_custom_command(TARGET 64bit_windows WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}" DEPENDS "plugins/${PLUGIN_TITLE}.so" COMMAND "./server64.exe")
    
elseif(("${CMAKE_SYSTEM_PROCESSOR}" MATCHES "x86_64" OR "${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "AMD64") AND "${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")
    add_custom_target(64bit_linux ALL DEPENDS ${NAME} WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
    add_custom_command(TARGET 64bit_linux WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}" DEPENDS "plugins/${PLUGIN_TITLE}.so" COMMAND "./mpsvrrel64")

elseif("${CMAKE_SYSTEM_PROCESSOR}" MATCHES "i.86" AND "${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
    add_custom_target(32bit_windows ALL DEPENDS ${NAME} WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
    add_custom_command(TARGET 32bit_linux WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}" DEPENDS "plugins/${PLUGIN_TITLE}.so" COMMAND "./server32.exe")

elseif("${CMAKE_SYSTEM_PROCESSOR}" MATCHES "i.86" AND "${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")
    add_custom_target(32bit_linux ALL DEPENDS ${NAME} WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
    add_custom_command(TARGET 32bit_linux WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}" DEPENDS "plugins/${PLUGIN_TITLE}.so" COMMAND "./mpsvrrel32")

else()
  message(FATAL_ERROR "server is not compatible with your platform or architecture.")
endif()
