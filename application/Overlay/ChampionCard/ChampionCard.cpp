#include <Overlay/ChampionCard/ChampionCard.hpp>
#include <utility>
#include <format>

unsigned int ChampionCard::s_counter{0};

ChampionCard::ChampionCard(Sprite icon, std::array<Sprite, 6> items = {})
    :
    m_uniqueId(s_counter++),
    m_icon{icon},
    m_items{std::move(items)}
{
    m_containerFlags =  ImGuiWindowFlags_NoTitleBar
                        | ImGuiWindowFlags_NoResize
                        | ImGuiWindowFlags_NoScrollbar
                        | ImGuiWindowFlags_NoScrollWithMouse
                        | ImGuiWindowFlags_NoDocking
                        | ImGuiWindowFlags_AlwaysAutoResize;
}


void ChampionCard::Draw()
{
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
    ImGui::PushStyleVar(ImGuiStyleVar_CellPadding, ImVec2(0.0f, 0.0f));

    ImGui::Begin(std::format("Champion Card##{}", m_uniqueId).c_str(), nullptr, m_containerFlags);
    ImGui::Image(m_icon.GetTextureID(), ImVec2(100, 100), m_icon.GetUV0(), m_icon.GetUV1());

    ImGui::SameLine(0.0, 0.0);
    ImGui::BeginTable(std::format("Champion Items##{}", m_uniqueId).c_str(), m_items.size() / 2, ImGuiTableFlags_SizingFixedFit);

    for (const auto & item : m_items)
    {
        ImGui::TableNextColumn();
        ImGui::Image(item.GetTextureID(), ImVec2(50, 50), item.GetUV0(), item.GetUV1());
    }

    ImGui::EndTable();
    ImGui::End();

    ImGui::PopStyleVar(2);
}

Sprite& ChampionCard::GetIcon()
{
    return m_icon;
}

std::array<Sprite, 6>& ChampionCard::GetItems()
{
    return m_items;
}
