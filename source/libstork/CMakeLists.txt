cmake_minimum_required(VERSION 3.16.1)

set(CMAKE_OSX_DEPLOYMENT_TARGET "10.14")

project(libstork LANGUAGES CXX)

add_library(libstork SHARED)
set_target_properties(libstork PROPERTIES
  CXX_STANDARD 20
  CXX_STANDARD_REQUIRED OFF
  CXX_EXTENSIONS OFF
  OUTPUT_NAME "stork"
)

if (MSVC)
  # make sure to export to lib as well as dll
  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

file(GLOB_RECURSE LIB_SOURCES "*.cpp")
file(GLOB_RECURSE LIB_HEADERS "*.hpp")
target_sources(libstork PRIVATE ${LIB_SOURCES} ${LIB_HEADERS})
install(TARGETS libstork)