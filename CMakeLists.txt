#
# @file CMakeLists.txt
# @brief CMake build configuration for the Data_Structure project.
#
# This file configures the build system to compile all source files except test.cpp,
# sets the C++ standard, and creates the main executable.
#

cmake_minimum_required(VERSION 3.10)
project(Data_Structure)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Only include main.cpp and all .cpp files except test.cpp
file(GLOB SOURCES "*.cpp")
list(REMOVE_ITEM SOURCES "${CMAKE_SOURCE_DIR}/test.cpp")

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})
