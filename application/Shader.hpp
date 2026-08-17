#pragma once
#include <string>
#include <unordered_map>

#include "glm/vec2.hpp"
#include "glm/vec4.hpp"

typedef struct
{
    unsigned int id;
    std::string filepath;
} ShaderInfo_T;

class Shader
{
public:
    Shader(const std::string&& vertexFilepath, const std::string&& fragmentFilepath);

    int CompileShader(const ShaderInfo_T& info);
    int CreateProgram();
    void Activate() const;

    void SetUniform(const std::string& name, glm::vec2 value);
    void SetUniform(const std::string& name, glm::vec4 value);
private:
    ShaderInfo_T m_vertex;
    ShaderInfo_T m_fragment;

    unsigned int m_program{};
    std::unordered_map<std::string, std::int32_t> m_uniforms;
};