project (ygopro)

cmake_minimum_required (VERSION 2.8) 
cmake_policy(SET CMP0005 OLD)

if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "Setting build type to 'Debug' as none was specified.")
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/macros")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(CheckCXXSourceRuns)
include(CheckIncludeFiles)

include (AutoFiles)
include (CreateLaunchers)

include (platform/settings)

if (MSVC)

else ()
    find_package(LibEvent REQUIRED)
    find_package(wxWidgets REQUIRED core base gl xml)
    find_package(Lua52 REQUIRED)
    find_package(OpenGL REQUIRED)
    include(${wxWidgets_USE_FILE})
    add_definitions( "-DHAVE_TYPE_TRAITS -DwxUSE_UNICODE" )
endif ()

add_subdirectory (netc)
add_subdirectory (sqlite3)
add_subdirectory (lzma)
