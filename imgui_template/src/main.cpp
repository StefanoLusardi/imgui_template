#include "example_app.hpp"

int main(int argc, char **argv)
{
    auto app = app::create_application();
    return app->Run(argc, argv);
}