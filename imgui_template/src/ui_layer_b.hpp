#pragma once

#include "ui_layer.hpp"
#include <imgui.h>


namespace app
{
class ui_layer_b : public ui_layer
{
public:
    ~ui_layer_b() = default;

    void UpdateUI() override
    {
		// ImGui::Begin("Layer B");
		// ImGui::Button("Button");
		// ImGui::End();

        ImDrawList* draw_list = ImGui::GetWindowDrawList();
        const float size = 200;
        static ImVec4 rgba_color = ImVec4(0.0f, 1.0f, 0.0f, 1.0f);
        const ImU32 color = ImColor(rgba_color);
        auto window_center_w = ImGui::GetWindowWidth() * 0.7f;
        auto window_center_h = ImGui::GetWindowHeight() * 0.7f;

        draw_list->AddRect(ImVec2(window_center_w, window_center_h), ImVec2(window_center_w+size, window_center_h+size), color);
        draw_list->AddRect(ImVec2(size, size), ImVec2(size*2, size*2), color);
    }
};

} // namespace app
