cmake_minimum_required(VERSION 3.10...3.24)

project(my_project)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include FetchContent module
include(FetchContent)

# Declare and configure GoogleTest
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE # Ensure timestamps match extraction time
)
FetchContent_MakeAvailable(googletest)

# Enable testing framework
enable_testing()

# Define the test executable
add_executable(my_tests test.cpp)

# Link the test executable with GoogleTest
target_link_libraries(my_tests gtest_main)
