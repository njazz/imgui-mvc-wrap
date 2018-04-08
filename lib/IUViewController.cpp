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
    drawMenu();

    // subs
    for (auto s: _subControllers)
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
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(padding, padding));

    ImGui::Begin(title.c_str(), &display, ImVec2(0,0), alpha, flags);
    
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, wp);

    _drawAllContents();
    _handleMouse();
    
    ImGui::PopStyleVar();
    
    ImGui::End();
    
    ImGui::PopStyleVar();
}

void IUViewController::drawMenu()
{
    if (menu)
        menu->draw();
}
