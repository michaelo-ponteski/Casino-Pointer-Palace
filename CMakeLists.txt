cmake_minimum_required(VERSION 3.10)

project(CasinoPointerPalace)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB HEADERS "include/*.hpp")
file(GLOB SOURCES "src/*.cpp")

add_executable(CasinoPointerPalace ${SOURCES})

target_include_directories(CasinoPointerPalace PUBLIC include)
