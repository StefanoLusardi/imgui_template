#pragma once

namespace app
{
class ui_layer
{
public:
    virtual ~ui_layer() = default;
    virtual void OnAttach() {}
    virtual void OnDetach() {}
    virtual void UpdateUI() = 0;
};

} // namespace app
