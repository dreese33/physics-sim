cmake_minimum_required(VERSION 3.10)

# project name
project(Physics_Sim)

# specify C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# directories
include_directories(src/windows)

# executables
add_executable(Physics_Sim
  main.cpp
  src/glad.c
  src/windows/window.cpp
)

# Libraries
find_package(glfw3 3.3 REQUIRED)
target_link_libraries(Physics_Sim glfw)