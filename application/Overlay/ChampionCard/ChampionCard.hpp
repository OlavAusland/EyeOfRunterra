#pragma once
#include <array>

#include <Overlay/Drawable_I.hpp>
#include <Core/Sprite.hpp>
#include <imgui.h>

class ChampionCard : public Drawable_I
{
private:
    static unsigned int s_counter;
public:
    ChampionCard(Sprite icon, std::array<Sprite, 6> items);

    Sprite& GetIcon();
    std::array<Sprite, 6>& GetItems();
    void Draw() override;
private:
    unsigned int m_uniqueId;

    ImGuiWindowFlags m_containerFlags;

    Sprite m_icon;
    std::array<Sprite, 6> m_items;
};
