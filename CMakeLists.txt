cmake_minimum_required(VERSION 3.10)

#set the project name
project(CaptureIt)

#VARIABLES:
set(EXECUTABLE_APP "App")
set(LIB_XORG "Xorg")
set(LIB_IGS "IGS")
set(ABSTRACT_LIB_PNG "APNG")
set(LIB_CONTROLLER "Controller")

set(APP_PATH "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
set(LIB_XORG_PATH "${CMAKE_CURRENT_SOURCE_DIR}/framework/xorg.cpp")
set(LIB_IGS_PATH "${CMAKE_CURRENT_SOURCE_DIR}/framework/session_interface.cpp")
set(ABSTRACT_LIB_PNG_PATH "${CMAKE_CURRENT_SOURCE_DIR}/framework/abstract_lib_png.cpp")
set(LIB_CONTROLLER_PATH "${CMAKE_CURRENT_SOURCE_DIR}/framework/controller.cpp")

#include X11 library from system
find_package(X11 REQUIRED)
link_libraries(${X11_LIBRARIES})
include_directories(${X11_INCLUDE_DIR})

add_executable(${EXECUTABLE_APP} ${APP_PATH})
add_library(${LIB_XORG} STATIC ${LIB_XORG_PATH})
add_library(${LIB_IGS} STATIC ${LIB_IGS_PATH})
add_library(${ABSTRACT_LIB_PNG} STATIC ${ABSTRACT_LIB_PNG_PATH})
add_library(${LIB_CONTROLLER} STATIC ${LIB_CONTROLLER_PATH})


target_link_libraries(${EXECUTABLE_APP} PRIVATE ${LIB_XORG})
target_link_libraries(${LIB_XORG} PRIVATE X11)
target_link_libraries(${EXECUTABLE_APP} PRIVATE ${LIB_CONTROLLER})
target_link_libraries(${LIB_CONTROLLER} PRIVATE ${LIB_IGS})
target_link_libraries(${LIB_CONTROLLER} PRIVATE ${ABSTRACT_LIB_PNG})
target_link_libraries(${ABSTRACT_LIB_PNG} PRIVATE png)