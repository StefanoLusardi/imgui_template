#pragma once

#include "ui_layer.hpp"
#include <imgui.h>

namespace app
{
class ui_layer_a : public ui_layer
{
public:
    ~ui_layer_a() = default;

    void UpdateUI() override
    {
        // ImGui::Begin("Layer A");
        // ImGui::Button("Button");
        // ImGui::End();
        
        ImDrawList* draw_list = ImGui::GetWindowDrawList();
        const float size = 50;
        static ImVec4 rgba_color = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
        const ImU32 color = ImColor(rgba_color);
        auto window_center_w = ImGui::GetWindowWidth() * 0.3f;
        auto window_center_h = ImGui::GetWindowHeight() * 0.3f;

        draw_list->AddCircle(ImVec2(window_center_w, window_center_h), size, color);
        draw_list->AddCircle(ImVec2(size, size), size, color);
        draw_list->AddCircle(ImVec2(ImGui::GetWindowWidth() - size, ImGui::GetWindowHeight() - size), size, color);
    }
};

} // namespace app
