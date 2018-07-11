//
//  IULayer.cpp
//  nseq
//
//  Created by Alex on 28/03/2018.
//  Copyright © 2018 Alex Nadzharov. All rights reserved.
//

#include "IULayer.hpp"

#include "IUWindowController.hpp"

#include "imgui_internal.h"

IULayer::IULayer()
    : IULayerBase()
{
    idString = "L" + std::to_string((long)this);
}

ImVec2 IULayer::_getContentSize()
{
    return ImVec2(contentSize.x < width ? width : contentSize.x, contentSize.y < height ? height : contentSize.y);
}

void IULayer::_setBounds()
{
    // TODO?
    const ImRect rect(x, y, width, height);
    ImGui::ItemSize(rect, padding);
    ImGui::ItemAdd(rect, 0, &rect);
}

void IULayer::_drawAllContents()
{
    if (hidden)
        return;

    IULayerBase::draw();
}

void IULayer::draw()
{
    if (manualLayout)
        ImGui::SetCursorPos(pos());

    ImGui::SetNextWindowContentSize(_getContentSize());

    auto wp = ImGui::GetStyle().WindowPadding;
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(padding, padding));

    if (ImGui::GetCurrentContext()->CurrentWindow)
        ImGui::BeginChild(ImGui::GetID(idString.c_str()), size());

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, wp);

    // base
    if (hidden)
        IULayerBase::draw();

    ImGui::PopStyleVar();

    if (ImGui::GetCurrentContext()->CurrentWindow)
        ImGui::EndChild();

    ImGui::PopStyleVar();
};

void IULayer::addSublayer(IULayer* v)
{
    if (!v)
        return;

    v->_parent = this;
    addComponent(v);
}

void IULayer::removeSublayer(IULayer* v)
{
    removeComponent(v);
    v->_parent = 0;
}

void IULayer::removeAllSublayers()
{
    for (auto d : _components)
        d->_parent = 0;

    clearComponents();
}

