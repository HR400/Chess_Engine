cmake_minimum_required(VERSION 3.19)
project(ChessEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(ChessEngine main.cpp chess.cpp)

target_link_libraries(ChessEngine PRIVATE
    glfw
    OpenGL::GL
)

if(APPLE)
    target_link_libraries(ChessEngine PRIVATE
        "-framework Cocoa"
        "-framework IOKit"
        "-framework CoreVideo"
    )
endif()