#pragma once
#include <memory>
#include <Core/Texture.hpp>

class TextureManager
{
public:
    static TextureManager& Instance();

    const std::shared_ptr<Texture>& GetTexture(const std::string& filepath);

    TextureManager(const TextureManager&) = delete;
    TextureManager& operator=(const TextureManager&) = delete;

    TextureManager(TextureManager&&) = delete;
    TextureManager& operator=(TextureManager&&) = delete;

private:
    TextureManager() = default;
    ~TextureManager();

    std::unordered_map<std::string, std::shared_ptr<Texture>> m_textures{{"none", std::make_shared<Texture>(100, 100)}};
};
