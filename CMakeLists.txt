cmake_minimum_required(VERSION 3.1)

project(MySFMLProject)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(MySFMLApp src/main.cpp)

target_link_libraries(MySFMLApp PRIVATE sfml-graphics sfml-window sfml-system)
