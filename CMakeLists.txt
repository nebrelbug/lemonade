project(potatoes)

include_directories( ${~/potatoes}/src )
include_directories( ${~/potatoes}/include )
include_directories( ${~/potatoes}/firmware )
include_directories( ${~/potatoes}/bin )

cmake_minimum_required(VERSION 3.6)   # CMake version check
project(potatoes)               # Create project "simple_example"
set(CMAKE_C_STANDARD 11)            # Enable c++11 standard

set(~/potatoes/include main.h)            # Add main.cpp file of project root directory as source file
add_executable(potatoes ${/Program Files}/PROS/toolchain/usr/arm-none-eabi)       # Add executable target with source files listed in SOURCE_FILES variable