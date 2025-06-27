#include "imgui/imgui_common.h"
#include "video.h"
#include <memory>
#include <cstddef>

ImGuiCallbackData* AddImGuiCallback(ImGuiCallback /*callback*/)
{
    static ImGuiCallbackData dummy{};
    return &dummy;
}

void ResetImGuiCallbacks()
{
}

std::unique_ptr<GuestTexture> LoadTexture(const uint8_t* /*data*/, size_t /*dataSize*/, RenderComponentMapping /*componentMapping*/)
{
    return nullptr;
}
