//
//  IIUView.cpp
//  imguiController
//
//  Created by Alex on 22/03/2018.
//

#include "IUView.hpp"

void IUView::addAction(int k, IUAction* o)
{
    o->sender = this;
    _actions[k].push_back(o);
};

void IUView::removeAction(int k, IUAction* o)
{
    auto it = std::find(_actions[k].begin(), _actions[k].end(), o);
    if (it != _actions[k].end())
        _actions[k].erase(it);
};

void IUView::removeAllActions(int k)
{
    _actions[k].clear();
};

//---

void IUView::updated(int key)
{
    for (IUAction* o : _actions[key]) {
        o->sender = this;
        o->action();
    }
}

// ---
void IUView::_handleMouse()
{
    if (!ImGui::IsMouseHoveringRect(pos(), size()))
        return;
    
    if (ImGui::IsMouseClicked(0))
        onMouseDown();
    
    if (ImGui::IsMouseReleased(0))
        onMouseUp();
    
    if (ImGui::IsMouseDragging())
        onMouseDrag();
    
}

// ---

void IUView::draw()
{
    if (manualLayout)
        ImGui::SetCursorPos(pos());
    
    ImGui::SetNextWindowContentSize(_getContentSize());
    
    auto wp = ImGui::GetStyle().WindowPadding;
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(padding, padding));
    
    ImGui::BeginChildFrame(ImGui::GetID(idString.c_str()), size());
    
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding,wp);
    
    _drawAllContents();
    _handleMouse();
    
    ImGui::PopStyleVar();
    
    ImGui::EndChildFrame();
    
    ImGui::PopStyleVar();
};
