#include <Core/Sprite.hpp>
#include <Core/TextureManager.hpp>

Sprite::Sprite()
{
    m_texture = TextureManager::Instance().GetTexture("none");
}

Sprite::Sprite(const std::string &filepath)
{
    m_texture = TextureManager::Instance().GetTexture(filepath);
}

Sprite::Sprite(const std::string &filepath, const ImVec2 &position, const ImVec2 &size)
    : Sprite(filepath)
{
    Crop(position, size);
}

void Sprite::Crop(const ImVec2 &position, const ImVec2 &size)
{
    const auto &textureSize = m_texture->GetSize();

    uv0 =
    {
        (position.x / textureSize.x),
        (position.y / textureSize.y)
    };

    uv1 =
    {
        ((position.x + size.x) / textureSize.x),
        ((position.y + size.y) / textureSize.y),
    };
}

const ImVec2 &Sprite::GetUV0() const { return uv0; }
const ImVec2 &Sprite::GetUV1() const { return uv1; }

unsigned int Sprite::GetTextureID() const
{
    return m_texture->GetTextureID();
}

const std::shared_ptr<Texture> &Sprite::GetTexture() const
{
    return m_texture;
}

void Sprite::SetTexture(const std::string &filepath)
{
    if (filepath == m_texture->GetFilepath()) { return; }

    m_texture = TextureManager::Instance().GetTexture(filepath);
}

Sprite::~Sprite() = default;
