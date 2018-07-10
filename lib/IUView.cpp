//
//  IIUView.cpp
//  imguiController
//
//  Created by Alex on 22/03/2018.
//

#include "IUView.hpp"

IUView::IUView()
{
    idString = "V" + std::to_string((long)this);
}

void IUView::addAction(int k, IUAction* o)
{
    o->sender = this;
    if (std::find(_actions[k].begin(), _actions[k].end(), o) == _actions[k].end())
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

//template<>
//void IUView::_classSpecificMouseHandler<IUView>()
//{
//    
//}

// ---
void IUView::_handleMouse()
{
    if (!ImGui::GetCurrentContext())
        return;
    if (!mouseEnabled)
        return;


    ImVec2 pos;
    
    if (_isMouseHover())
        onMouseHover(pos);
    else
        onMouseExit(pos);

    if (_isMouseDown()) {
        onMouseDown(pos);
    }

    if (_isMouseReleased())
        onMouseUp(pos);

    if (_isMouseDragged())
        onMouseDrag(pos);
    
}

// ---

void IUView::draw()
{
    //if (!ImGui::GetCurrentContext()) return;

    if (manualLayout)
        ImGui::SetCursorPos(pos());

    ImGui::SetNextWindowContentSize(_getContentSize());

    auto wp = ImGui::GetStyle().WindowPadding;
    auto fp = ImGui::GetStyle().FramePadding;

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(padding, padding));
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(padding, padding));

    ImGui::BeginChildFrame(ImGui::GetID(idString.c_str()), size());

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, wp);
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, fp);

    _drawAllContents();

    ImGui::PopStyleVar();
    ImGui::PopStyleVar();

    ImGui::EndChildFrame();
    ImGui::PopStyleVar();
    ImGui::PopStyleVar();
    
    //_hoveringView = ImGui::IsItemHovered();
    _handleMouse();
    _shortcutComponents();
    
//    _updateComponents();
};

// ---
void IUView::removeFromParentView()
{
    if (_parent) {
        _parent->removeComponent(this);
    }
}
