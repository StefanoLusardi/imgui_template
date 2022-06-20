#pragma once

#include "application.hpp"
#include "ui_layer.hpp"

#include <map>
#include <memory>
#include <string>


namespace app
{
class ExampleApp : public Application
{
public:
    explicit ExampleApp() = default;
    ~ExampleApp();

    void UpdateUi() override;
    void OnInit() override;
    void OnShutdown() override;

    bool AddUiLayer(const std::string& layer_name, const std::shared_ptr<ui_layer>& layer);
    bool RemoveUiLayer(const std::string& layer_name);

private:
    std::map<std::string, std::shared_ptr<ui_layer>> _ui_layers;
};

} // namespace app