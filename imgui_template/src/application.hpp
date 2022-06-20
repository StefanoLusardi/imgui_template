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
    virtual void UpdateUi() = 0;

protected:
    virtual void OnInit() = 0;
    virtual void OnShutdown() = 0;

private:
    bool Init();

    GLFWwindow *window;
};

std::unique_ptr<Application> create_application();

} // namespace app
