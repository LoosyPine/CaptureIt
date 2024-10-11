#cmake_minimum_required(VERSION 3.10)

# Set some basic project attributes
#project (CuptureIt
	#VERSION 0.1
	#DESCRIPTION "A Hello World Project")

# This project will output an executable file
#add_executable(${PROJECT_NAME} CuptureIt.cpp)

# Create a simple configuration header
#configure_file(config.h.in config.h)

# Include the configuration header in the build
#target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_BINARY_DIR}")

cmake_minimum_required(VERSION 3.10)

set(CMAKE_PROJECT_NAME "CaptureIt")
set(LIBPNG_PATH "/usr/lib/x86_64-linux-gnu/libpng.a")

#set the project name
project(CMAKE_PROJECT_NAME)

find_package(X11 REQUIRED)
link_libraries(${X11_LIBRARIES})
include_directories(${X11_INCLUDE_DIR})

#add the executable
add_executable(App source/main.cpp)
target_link_libraries(App png)
