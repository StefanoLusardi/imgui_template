#pragma once

#include "application.hpp"

namespace app
{
class ExampleApp : public Application
{
public:
    ExampleApp() = default;
    ~ExampleApp() = default;

    void UpdateUI() override;

private:
    bool show_demo_window = true;
    bool show_another_window = false;
};

} // namespace app