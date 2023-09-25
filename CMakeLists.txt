cmake_minimum_required(VERSION 3.16.1)

set(CMAKE_OSX_DEPLOYMENT_TARGET "10.14")

project(stork LANGUAGES CXX)

add_subdirectory("source/libstork")
add_subdirectory("source/interpreter")


if(NOT EXISTS ${PROJECT_BINARY_DIR}/.gitignore)
  file(WRITE ${PROJECT_BINARY_DIR}/.gitignore "*")
endif()