#pragma once
#include <string>
#include <vector>
#include <glad/glad.h>
#include <glfw/glfw3.h>

#include "imgui.h"

namespace Core
{
    struct ApplicationSpecification
    {
        const std::string name;
        const int width, height;
        const std::vector<std::pair<int, int>> windowHints;
    };

    class Application
    {
    public:
        Application(const ApplicationSpecification& specification);

        void Run();
    private:
        bool m_running{false};

        ImVec4 m_cc{0.0f, 0.0f, 0.0f, 0.0f};

        GLFWwindow* window{nullptr};
    };
}
