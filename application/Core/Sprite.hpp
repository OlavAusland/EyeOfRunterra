#pragma once
#include <Core/Texture.hpp>
#include <memory>

class Sprite
{
public:
    Sprite();
    Sprite(const std::string& filepath);
    Sprite(const std::string& filepath, const ImVec2& position, const ImVec2& size);

    void Crop(const ImVec2& position, const ImVec2& size);
    void SetTexture(const std::string& filepath);

    ~Sprite();

    [[nodiscard]] const ImVec2 &GetUV0() const;
    [[nodiscard]] const ImVec2 &GetUV1() const;
    [[nodiscard]] unsigned int GetTextureID() const;
    [[nodiscard]] const std::shared_ptr<Texture>& GetTexture() const;

private:
    std::shared_ptr<Texture> m_texture;

    ImVec2 uv0{0.0, 0.0};
    ImVec2 uv1{1.0, 1.0};
};
