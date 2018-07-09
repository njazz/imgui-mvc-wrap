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
    //    const ImRect rect(x,y,width,height);
    //    ImGui::ItemSize(rect, padding);
    //    ImGui::ItemAdd(rect, 0, &rect);
}

void IULayer::_drawAllContents()
{
    _setBounds();
    drawLayerContents();
//    drawContents();
    if (!hidden)
    _drawComponents();
}

void IULayer::draw()
{
    // ImGui::SetWindowFontScale(scale());

    if (manualLayout)
        ImGui::SetCursorPos(pos());

    ImGui::SetNextWindowContentSize(_getContentSize());

    auto wp = ImGui::GetStyle().WindowPadding;
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(padding, padding));

    if (ImGui::GetCurrentContext()->CurrentWindow)
        ImGui::BeginChild(ImGui::GetID(idString.c_str()), size());

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, wp);

    _drawAllContents();

    ImGui::PopStyleVar();

    if (ImGui::GetCurrentContext()->CurrentWindow)
        ImGui::EndChild();

    ImGui::PopStyleVar();
};

//void IULayer::_drawSublayers()
//{
//    if (hidden)
//        return;
//
//    for (auto v:_sublayers) {
//        v->draw();
//    }
//};

void IULayer::addSubview(IULayer* v)
{
    if (!v)
        return;

//    _sublayers.push_back(v);
    addComponent(v);
    v->_parent = this;
//    v->setWindowController(_windowController);
}

void IULayer::removeSubview(IULayer* v)
{
    //_sublayers.erase(std::remove(_sublayers.begin(), _sublayers.end(), v), _sublayers.end());
    removeComponent(v);
    v->_parent = 0;
}

void IULayer::removeAllSubviews()
{
    for (auto d : _components)
        d->_parent = 0;

    clearComponents();
    //_sublayers.clear();
}


