#include "imgui.h"

ImGuiIO _io;

namespace ImGui {
ImGuiIO& GetIO() { return _io; }
}

ImGuiIO::ImGuiIO() {}
