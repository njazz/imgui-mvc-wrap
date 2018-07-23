//
#include "IUMainMenuBase.hpp"

void IUMainMenuBase::draw()
{
    /// \todo font scale
    //    float fontScale = ImGui::GetCurrentWindow()->FontWindowScale;
    //    ImGui::SetWindowFontScale(1);

    ImGui::BeginMainMenuBar();

    IUBaseT<IUMenuBase>::draw();

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
    ImGui::BeginMenuBar();

    IUBaseT<IUMenuBase>::draw();

    ImGui::EndMenuBar();
}

void IUMenuBarBase::addMenu(IUMenuBase* m, std::string name)
{
    m->name = name;
    addComponent(m);
}

