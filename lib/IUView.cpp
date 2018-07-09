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

// ---
void IUView::_handleMouse()
{
    if (!ImGui::GetCurrentContext())
        return;

    if (!mouseEnabled)
        return;

    // DEBUG:
    //        ImGui::BeginTooltip();
    //        ImGui::Text("hover %f %f / mouse %f %f / win %f %f", posInWindow().x, posInWindow().y, ImGui::GetIO().MousePos.x,ImGui::GetIO().MousePos.y ,ImGui::GetWindowPos().x,ImGui::GetWindowPos().y);
    //        ImGui::EndTooltip();

    //ImGui::InvisibleButton(const char *str_id, const ImVec2 &size);

    //if (!ImGui::IsMouseHoveringRect(posInWindow(), ImVec2(posInWindow().x  + width, posInWindow().y  + height)))

    //    if (!_hoveringView)
    //        return;

    if (_hoveringView)
        mouseHoverAction();
    else
        return;

    //    if (!ImGui::IsMouseHoveringRect(ImGui::GetItemRectMin(), ImGui::GetItemRectMax()))
    //        return;

    if (ImGui::IsMouseClicked(0)) {
        mouseDownAction();
    }

    if (ImGui::IsMouseReleased(0))
        mouseUpAction();

    if (ImGui::IsMouseDragging())
        mouseDragAction();
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
    _hoveringView = ImGui::IsItemHovered();
    _handleMouse();

    ImGui::PopStyleVar();
    ImGui::PopStyleVar();
    
    _shortcutComponents();
};

// ---
void IUView::removeFromParentView()
{
    if (_parent) {
        _parent->removeComponent(this);
    }
}
