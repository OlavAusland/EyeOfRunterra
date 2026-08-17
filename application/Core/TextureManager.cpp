#include <Core/TextureManager.hpp>
#include <print>

TextureManager &TextureManager::Instance()
{
    static TextureManager instance;
    return instance;
}


const std::shared_ptr<Texture>& TextureManager::GetTexture(const std::string& filepath)
{
    if (!m_textures.contains(filepath))
    {
        m_textures[filepath] = std::make_shared<Texture>(filepath);

        std::println(stdout, "Added texture: {}", filepath);
    }

    return m_textures[filepath];
}

TextureManager::~TextureManager()
{
    m_textures.clear();
}
