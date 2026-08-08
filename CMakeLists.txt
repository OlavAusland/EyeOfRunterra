cmake_minimum_required(VERSION 4.3)
project(EyeOfRuneterra)

set(CMAKE_CXX_STANDARD 23)
set(GRAPHIC_BACKEND "OpenGL")

add_executable(EyeOfRuneterra main.cpp)

add_subdirectory(vendors)
add_subdirectory(application)

target_link_options(${CMAKE_PROJECT_NAME} PRIVATE "LINKER:-lstdc++exp")
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
        ImGUI::ImGUI
        "-lstdc++exp"
)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/vendors"
        "${CMAKE_CURRENT_SOURCE_DIR}/application"
)