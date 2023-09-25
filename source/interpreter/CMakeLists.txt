cmake_minimum_required(VERSION 3.16.1)

set(CMAKE_OSX_DEPLOYMENT_TARGET "10.14")

project(stork LANGUAGES CXX)

add_executable(stork)
set_target_properties(stork PROPERTIES
  CXX_STANDARD 20
  CXX_STANDARD_REQUIRED OFF
  CXX_EXTENSIONS OFF
)

target_include_directories(stork PRIVATE "../libstork")
target_link_directories(stork PRIVATE "../libstork")

file(GLOB_RECURSE BIN_SOURCES "*.cpp")
file(GLOB_RECURSE BIN_HEADERS "*.hpp")

target_sources(stork PRIVATE ${BIN_SOURCES} ${BIN_HEADERS})
target_link_libraries(stork PRIVATE libstork)

install(TARGETS stork)
