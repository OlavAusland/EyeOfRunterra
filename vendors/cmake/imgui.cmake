add_library(ImGUI STATIC)
add_library(ImGUI::ImGUI ALIAS ImGUI)

set(IMGUI_DIRECTORY "${CMAKE_SOURCE_DIR}/vendors/imgui")

target_sources(ImGUI PUBLIC
        "${IMGUI_DIRECTORY}/imgui.cpp"
        "${IMGUI_DIRECTORY}/imgui_draw.cpp"
        "${IMGUI_DIRECTORY}/imgui_demo.cpp"
        "${IMGUI_DIRECTORY}/imgui_tables.cpp"
        "${IMGUI_DIRECTORY}/imgui_widgets.cpp"
)

target_include_directories(ImGUI PUBLIC ${IMGUI_DIRECTORY})

if(GRAPHIC_BACKEND STREQUAL "OpenGL")
    find_package(OpenGL REQUIRED)

    target_sources(ImGUI PUBLIC
        "${IMGUI_DIRECTORY}/backends/imgui_impl_opengl3.cpp"
        "${IMGUI_DIRECTORY}/backends/imgui_impl_glfw.cpp"
    )

    target_link_libraries(ImGUI PUBLIC
            glfw
            glm::glm
            glad::glad
            OpenGL::GL
    )
else()
    message(FATAL_ERROR "Invalid Backend: ${GRAPHIC_BACKEND}")
endif()