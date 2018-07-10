//
#include "IUMainMenuBase.hpp"

void IUMainMenuBase::draw()
{
//    float fontScale = ImGui::GetCurrentWindow()->FontWindowScale;
//    ImGui::SetWindowFontScale(1);

    ImGui::BeginMainMenuBar();

    _drawComponents();
    _shortcutComponents();

    ImGui::EndMainMenuBar();

//    ImGui::SetWindowFontScale(fontScale);

}

void IUMainMenuBase::addMenu(IUMenuBase* m, std::string name)
{
    m->name = name;
    addComponent(m);
}

// ---

void IUMenuBarBase::draw()
{
//    float fontScale = ImGui::GetCurrentWindow()->FontWindowScale;
//    ImGui::SetWindowFontScale(1);

    ImGui::BeginMenuBar();

    _drawComponents();
    _shortcutComponents();

    ImGui::EndMenuBar();

//    ImGui::SetWindowFontScale(fontScale);

}

void IUMenuBarBase::addMenu(IUMenuBase* m, std::string name)
{
    m->name = name;
    addComponent(m);
}

