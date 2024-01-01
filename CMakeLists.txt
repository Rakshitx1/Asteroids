cmake_minimum_required(VERSION 3.5.0)

project(MySFMLProject VERSION 0.1.0 LANGUAGES CXX)

# Set the build type to Debug by default if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Release)

# Find SFML libraries
find_package(SFML 2.5 COMPONENTS graphics window system audio network REQUIRED)

# List your source files
set(SOURCES 
    src/main.cpp
    src/Game.cpp
)

# Create an executable
add_executable(MySFMLApp ${SOURCES})

# Include directories for SFML and your custom include directory
target_include_directories(MySFMLApp PRIVATE ${SFML_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/inc)

# Link the executable with SFML libraries
target_link_libraries(MySFMLApp PRIVATE sfml-graphics sfml-window sfml-system sfml-audio sfml-network)

# Set compiler flags
target_compile_options(MySFMLApp PRIVATE -m64)

# Set compiler flags for Debug
target_compile_options(MySFMLApp PRIVATE $<$<CONFIG:DEBUG>: -O0 -g -Wall>)

# Set compiler flags for Release
target_compile_options(MySFMLApp PRIVATE $<$<CONFIG:RELEASE>: -O3>)
