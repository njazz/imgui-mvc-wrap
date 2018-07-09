//
//  IUViewController.cpp
//  imguiController
//
//  Created by Alex on 22/03/2018.
//

#include "IUViewController.hpp"
#include "IUMainMenuBase.hpp"
#include "IUWindowController.hpp"

void IUViewController::setWindowController(IUWindowController* w)
{
    IUView::setWindowController(w);
}

void IUViewController::draw()
{
//    ImGui::SetWindowFontScale(scale());

    if (dockSpace)
        ImGui::BeginDockspace();
    
    drawMenu();

    // subs
    for (auto s : _subControllers)
        if (!s->hidden)
            s->draw();
    if (_subControllers.size())
        return;

    // setup
    ImGui::SetNextWindowPos(pos());
    //if (flags & !ImGuiWindowFlags_NoResize)
    ImGui::SetNextWindowSize(size(), ImGuiCond_Always);
    ImGui::SetNextWindowContentSize(_getContentSize());

    // draw
    auto wp = ImGui::GetStyle().WindowPadding;
    auto fp = ImGui::GetStyle().FramePadding;
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(padding, padding));
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(padding, padding));

    if (dockable)
        ImGui::BeginDock(title.c_str(), &display, flags);
    else
        ImGui::Begin(title.c_str(), &display, ImVec2(0, 0), alpha, flags);

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, wp);
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, fp);

    _drawAllContents();
    _handleMouse();

    ImGui::PopStyleVar();
    ImGui::PopStyleVar();

    if (dockable)
        ImGui::EndDock();
    else
    ImGui::End();

    ImGui::PopStyleVar();
    ImGui::PopStyleVar();
    
    if (dockSpace)
        ImGui::EndDockspace();
    
//    _shortcutComponents();
}

void IUViewController::drawMenu()
{
    if (menu)
        menu->draw();
}
