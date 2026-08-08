#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <Core/Application.hpp>

int main()
{
    Core::Application application
    {
        Core::ApplicationSpecification
        {
            .name{"EyeOfRuneterra"},
            .width = 640,
            .height = 640,
            .windowHints
            {
                {GLFW_DECORATED,                GLFW_FALSE},
                {GLFW_TRANSPARENT_FRAMEBUFFER,  GLFW_TRUE},
                {GLFW_FLOATING,                 GLFW_TRUE},
                {GLFW_MOUSE_PASSTHROUGH,        GLFW_TRUE},
                {GLFW_CONTEXT_VERSION_MAJOR,    4},
                {GLFW_CONTEXT_VERSION_MINOR,    6},
                {GLFW_OPENGL_PROFILE,           GLFW_OPENGL_CORE_PROFILE},
                {GLFW_SAMPLES,                  4}
            }
        }
    };

    application.Run();

    return 0;
}
