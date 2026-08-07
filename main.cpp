#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_glfw.h>
#include <imgui/backends/imgui_impl_opengl3.h>

#include <print>
#include <unordered_map>

int main()
{

    if (!glfwInit())
    {
        std::println(stderr, "[ ERROR ] Failed to initialize GLFW.");
        return EXIT_FAILURE;
    }

    const std::unordered_map<int, int> hints =
    {
        {GLFW_DECORATED,                GLFW_FALSE },
        {GLFW_TRANSPARENT_FRAMEBUFFER,  GLFW_TRUE},
        {GLFW_FLOATING,                 GLFW_TRUE},
        {GLFW_MOUSE_PASSTHROUGH,        GLFW_TRUE},
        {GLFW_CONTEXT_VERSION_MAJOR,    4},
        {GLFW_CONTEXT_VERSION_MINOR,    6},
        {GLFW_OPENGL_PROFILE,           GLFW_OPENGL_CORE_PROFILE},
        {GLFW_SAMPLES,                  4},
    };

    for (const auto& hint : hints)
    {
        glfwWindowHint(hint.first, hint.second);
    }

    GLFWwindow* window = glfwCreateWindow(640, 640, "EyeOfRuneterra",nullptr, nullptr);

    if (!window)
    {
        std::println(stderr, "[ ERROR ] Failed to create GLFW window.");
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        std::println(stderr, "[ ERROR ] Failed to initialize GLAD.");
        return -1;
    }

    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    ImVec4 clearColor = ImVec4(0.45f, 0.55f, 0.60f, 0.10f);
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        ImGui::DockSpaceOverViewport(0, nullptr, ImGuiDockNodeFlags_PassthruCentralNode);
        glfwSetWindowAttrib(window, GLFW_MOUSE_PASSTHROUGH, !io.WantCaptureMouse);

        glClearColor(clearColor.x * clearColor.w, clearColor.y * clearColor.w, clearColor.z * clearColor.w, clearColor.w);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        ImGui::Begin("Info");
        ImGui::Button("Hello", ImVec2(60, 60));
        ImGui::End();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
