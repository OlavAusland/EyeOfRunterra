#pragma once
#include <string>

#include "imgui.h"
#include "../Shader.hpp"

class Texture
{
public:
    explicit Texture(int width, int height);
    explicit Texture(const std::string& filepath);

    void SetTextureSize(unsigned int width, unsigned int height);
    [[nodiscard]] std::string& GetFilepath();
    [[nodiscard]] unsigned int GetTextureID() const;
    [[nodiscard]] ImVec2 GetSize() const;

    ~Texture();
private:
    unsigned int m_id{};
    int m_height{};
    int m_width{};

    std::string m_filepath;
};
