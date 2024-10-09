cmake_minimum_required(VERSION 3.10)

set(CMAKE_PROJECT_NAME "TurboScreenshotMaker")

#set the project name
project(CMAKE_PROJECT_NAME)

find_package(X11 REQUIRED)
link_libraries(${X11_LIBRARIES})
include_directories(${X11_INCLUDE_DIR})

#add the executable
add_executable(App source/main.cpp)
