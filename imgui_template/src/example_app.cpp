#include "example_app.hpp"
#include <imgui.h>

#include "ui_layer_a.hpp"
#include "ui_layer_b.hpp"

namespace app
{
std::unique_ptr<Application> create_application()
{
    return std::make_unique<ExampleApp>();
}

ExampleApp::~ExampleApp()
{
    for (auto&& layer : _ui_layers)
        layer.second->OnDetach();

    _ui_layers.clear();
}

void ExampleApp::OnInit()
{
    AddUiLayer("Layer_A", std::make_shared<ui_layer_a>());
    AddUiLayer("Layer_B", std::make_shared<ui_layer_b>());

    // ImGuiStyle* style = &ImGui::GetStyle();
    // style->Colors[ImGuiCol_WindowBg] = ImVec4(1.0f, 1.0f, 1.0f, 1.00f);
}

void ExampleApp::OnShutdown()
{
}

bool ExampleApp::AddUiLayer(const std::string& layer_name, const std::shared_ptr<ui_layer>& layer) 
{
    if (auto layer_iterator = _ui_layers.find(layer_name); layer_iterator == _ui_layers.end())
    {
        _ui_layers.emplace(layer_name, layer);
        layer->OnAttach();
        return true;
    }

    return false;
}

bool ExampleApp::RemoveUiLayer(const std::string& layer_name)
{
    if (auto layer_iterator = _ui_layers.find(layer_name); layer_iterator != _ui_layers.end())
    {
        layer_iterator->second->OnDetach();
        _ui_layers.erase(layer_name);
        return true;
    }

    return false;
}

void ExampleApp::UpdateUi()
{
    // ImGui::ShowDemoWindow();
    // return;

    {
        static ImGuiWindowFlags main_window_flags =
            ImGuiWindowFlags_NoBringToFrontOnFocus |
            ImGuiWindowFlags_NoDecoration |
            ImGuiWindowFlags_AlwaysAutoResize |
            ImGuiWindowFlags_NoSavedSettings |
            ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_NoNav;

        const ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->WorkPos);
        ImGui::SetNextWindowSize(viewport->WorkSize);

        if (ImGui::Begin("MainWindow", NULL, main_window_flags))
        {
            // ImDrawList* draw_list = ImGui::GetWindowDrawList();
            // const float size = 50;
            // static ImVec4 rgba_color = ImVec4(1.0f, 1.0f, 0.4f, 1.0f);
            // const ImU32 color = ImColor(rgba_color);
            // auto window_center_w = ImGui::GetWindowWidth() * 0.5f;
            // auto window_center_h = ImGui::GetWindowHeight() * 0.5f;
            // draw_list->AddCircle(ImVec2(window_center_w, window_center_h), size, color);

            // draw_list->AddCircle(ImVec2(size, size), size, color);
            // draw_list->AddCircle(ImVec2(ImGui::GetWindowWidth() - size, ImGui::GetWindowHeight() - size), size, color);

            for (auto&& [layer_name, layer] : _ui_layers)
                layer->UpdateUI();
        }

        ImGui::End();
    }

    {
        static ImGuiWindowFlags ui_info_flags =
            ImGuiWindowFlags_NoDecoration |
            ImGuiWindowFlags_AlwaysAutoResize |
            ImGuiWindowFlags_NoSavedSettings |
            ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_NoNav |
            ImGuiWindowFlags_NoFocusOnAppearing;

        const float PAD = 10.0f;
        const ImGuiViewport* viewport = ImGui::GetMainViewport();
        const auto window_pos = ImVec2{ viewport->WorkSize.x - PAD, viewport->WorkSize.y - PAD };
        const auto window_pos_pivot = ImVec2{ 1.0f, 1.0f };
        ImGui::SetNextWindowPos(window_pos, ImGuiCond_Always, window_pos_pivot);
        ImGui::SetNextWindowBgAlpha(0.2f);

        ImGui::Begin("UI Info", nullptr, ui_info_flags);
        ImGui::Text("%.3f ms/frame", 1000.0f / ImGui::GetIO().Framerate);
        ImGui::Text("%.1f FPS", ImGui::GetIO().Framerate);
        ImGui::End();
    }
}

} // namespace app
