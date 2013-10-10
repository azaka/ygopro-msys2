project (netc)

if (NOT WIN32 AND NOT APPLE)
    include (FindX11)   
endif ()

set (AUTO_FILES_RESULT)
if (MSVC)
    AutoFiles("." "res" "\\.(rc)$")
    AutoFiles("." "src" "\\.(cpp|c|h)$")
else ()
    AutoFiles("." "src" "\\.(cpp|c|h)$")
endif ()

if (MSVC)
    add_executable (netc WIN32 ${AUTO_FILES_RESULT})
else ()
    add_executable (netc ${AUTO_FILES_RESULT})
endif ()

target_link_libraries (netc sqlite3 lzma)

if (MSVC)
    target_link_libraries (netc wxwidgets sqlite3 lua event)
else ()
    target_link_libraries (netc ${LIBEVENT_LIBRARIES} ${LUA_LIBRARIES}
                                   ${wxWidgets_LIBRARIES} ${OPENGL_gl_LIBRARY})
    include_directories (${LUA_INCLUDE_DIR} ${LIBEVENT_INCLUDE_DIR}
                         ${wxWidgets_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIR})
    target_link_libraries (netc ${CMAKE_THREAD_LIBS_INIT} ${DL_LIBRARIES})
endif ()
if (WIN32)
    target_link_libraries (netc ws2_32 winmm gdi32 kernel32 user32 imm32 opengl32)
endif ()

create_target_launcher(netc WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
create_default_target_launcher(netc WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})