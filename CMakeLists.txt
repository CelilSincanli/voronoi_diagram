cmake_minimum_required(VERSION 3.0)
set(PROJECT_NAME voronoi_diagram)
project(${PROJECT_NAME} VERSION 1.0.0 LANGUAGES CXX)

# Add your project's source files
file(GLOB source_files "src/*.cpp")

set(SOURCES ${source_files})
set(CMAKE_CXX_STANDARD 11)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED COMPONENTS audio graphics window system network)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE "include" "lib")
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio sfml-network)