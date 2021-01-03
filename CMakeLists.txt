cmake_minimum_required(VERSION 3.1)

# Name the project
project(design_pattern)

# Include the 'include' of the project itself
include_directories("include")

# The file(GLOB...) allows for wildcard additions
file(GLOB SRCS
    "include/*.h"
    "src/*.cpp")

# Add an executable target called ConvexHull to be build from 
# the source files.
add_executable(design_pattern ${SRCS})

# Install the executeable program in the bin folder of the
# current project directory.
install(TARGETS design_pattern DESTINATION ${CMAKE_SOURCE_DIR}/bin)
