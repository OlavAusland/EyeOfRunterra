#define STB_IMAGE_IMPLEMENTATION

#include <iostream>
#include <ostream>
#include <../Texture.hpp>
#include <glad/glad.h>
#include <stb/stb_image.h>

Texture::Texture(const std::string& filepath)
    : m_filepath(filepath)
{
    glGenTextures(1, &m_id);
    glBindTexture(GL_TEXTURE_2D, m_id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    unsigned char* buffer = stbi_load(filepath.c_str(), &m_width, &m_height, nullptr, 4);



    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, buffer);

    stbi_image_free(buffer);
}

Texture::Texture(const int width, const int height)
    : m_height(height), m_width(width)
{
    glGenTextures(1, &m_id);
    glBindTexture(GL_TEXTURE_2D, m_id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
}

void Texture::SetTextureSize(const unsigned int width, const unsigned int height)
{
    m_width = static_cast<int>(width);
    m_height = static_cast<int>(height);

    glBindTexture(GL_TEXTURE_2D, m_id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
}

std::string& Texture::GetFilepath()
{
    return m_filepath;
}

unsigned int Texture::GetTextureID() const
{
    return m_id;
}

ImVec2 Texture::GetSize() const
{
    return {static_cast<float>(m_width), static_cast<float>(m_height)};
}

Texture::~Texture()
{
    std::cout << "Texture Texture Destructor" << std::endl;
}

