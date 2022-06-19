#pragma once

#include "imgui.h"
#include <memory>

struct GLFWwindow;

namespace app
{
class Application
{
public:
    Application();
    virtual ~Application();

    int Run(int argc, char **argv);
    virtual void UpdateUI() = 0;

protected:
    ImVec4 clear_color = ImVec4(0.0f, 0.7f, 0.3f, 1.0f);

private:
    bool Init();
    void Shutdown();

private:
    GLFWwindow *window;
};

std::unique_ptr<Application> create_application();

} // namespace app
