cmake_minimum_required(VERSION 3.10)

# Set the project name
project(CasinoPointerPalace)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
file(GLOB SOURCES "src/*.cpp")
add_executable(CasinoPointerPalace ${SOURCES})

# Include directories
target_include_directories(CasinoPointerPalace PRIVATE include)

# Link libraries (if any)
# target_link_libraries(CasinoPointerPalace <library_name>)
