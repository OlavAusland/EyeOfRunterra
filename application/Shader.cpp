#include <Shader.hpp>
#include <glad/glad.h>
#include <cstdint>
#include <fstream>
#include <print>

Shader::Shader(const std::string&& vertexFilepath, const std::string&& fragmentFilepath)
    :
    m_vertex
    {
        .id = glCreateShader(GL_VERTEX_SHADER),
        .filepath = vertexFilepath
    },
    m_fragment
    {
        .id = glCreateShader(GL_FRAGMENT_SHADER),
        .filepath = fragmentFilepath
    }
{
    if (CompileShader(m_vertex) && CompileShader(m_fragment) && CreateProgram())
    {
        //std::println("[ INFO ] Compiled shader.");
    }
}

int Shader::CompileShader(const ShaderInfo_T& info)
{
    std::int32_t status{0};
    std::string log(2048, '\0');

    std::ifstream file(info.filepath, std::ios::binary);

    if (!file)
    {
        std::println(stderr, "[ ERROR ] Faile to open file: {}", info.filepath);
        return -1;
    }

    std::string buffer{std::istreambuf_iterator(file), std::istreambuf_iterator<char>()};
    const char* source = buffer.c_str();

    glShaderSource(info.id, 1, &source, nullptr);
    glCompileShader(info.id);

    glGetShaderiv(info.id, GL_COMPILE_STATUS, &status);

    if (!status)
    {
        glGetShaderInfoLog(info.id, log.size(), nullptr, log.data());
        std::println(stderr, "[ ERROR ] Failed to compile shader: {}\n{}", info.filepath, log);
    }

    return status;
}

int Shader::CreateProgram()
{
    std::int32_t status{};
    std::string log(2048, '\0');

    m_program = glCreateProgram();

    glAttachShader(m_program, m_vertex.id);
    glAttachShader(m_program, m_fragment.id);
    glLinkProgram(m_program);

    glGetProgramiv(m_program, GL_LINK_STATUS, &status);

    if (!status)
    {
        glGetProgramInfoLog(m_program, log.size(), nullptr, log.data());
        std::println(stderr, "[ ERROR ] Failed to create program:\n{}", log);
    }

    glDetachShader(m_program, m_vertex.id);
    glDetachShader(m_program, m_fragment.id);

    return status;
}

void Shader::Activate() const
{
    glUseProgram(m_program);
}


void Shader::SetUniform(const std::string& name, glm::vec2 value)
{
    if (!m_uniforms.contains(name))
    {
        m_uniforms[name] = glGetUniformLocation(m_program, name.c_str());
    }

    glUniform2fv(m_uniforms[name], 1, &value[0]);
}


void Shader::SetUniform(const std::string& name, glm::vec4 value)
{
    if (!m_uniforms.contains(name))
    {
        m_uniforms[name] = glGetUniformLocation(m_program, name.c_str());
    }

    glUniform4fv(m_uniforms[name], 1, &value[0]);
}
