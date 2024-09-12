cmake_minimum_required(VERSION 3.10)
project(cars)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)

# Include the FindMySQL++ module
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

# Find packages
find_package(MySQL++ REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)

# ASIO include directory
find_path(ASIO_INCLUDE_DIR asio.hpp PATHS /usr/include)

# Include directories
include_directories(
    /home/razvan/Desktop/Nokia/CARS/cars/crow/include
    ${MYSQL++_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIRS}
    ${ASIO_INCLUDE_DIR} # Add this line to include ASIO
)

# Add the main executable
add_executable(main main.cpp)

# Link libraries to the executable
target_link_libraries(main
    ${MySQL++_LIBRARIES}
    ${Boost_LIBRARIES}
    pthread
)
