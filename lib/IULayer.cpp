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
    _drawSubviews();
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

    _drawAllContents();

    ImGui::PopStyleVar();

    if (ImGui::GetCurrentContext()->CurrentWindow)
        ImGui::EndChild();

    ImGui::PopStyleVar();
};

void IULayer::_drawSubviews()
{
    if (hidden)
        return;

    for (int i = 0; i < _subviews.size(); i++) {
        _subviews[i]->draw();
    }
};

void IULayer::addSubview(IULayer* v)
{
    if (!v)
        return;

    _subviews.push_back(v);
    v->_parent = this;
    v->setWindowController(_windowController);
}

void IULayer::removeSubview(IULayer* v)
{
    _subviews.erase(std::remove(_subviews.begin(), _subviews.end(), v), _subviews.end());
}

void IULayer::removeAllSubviews()
{
    for (IULayer* d : _subviews)
        d->_parent = 0;

    _subviews.clear();
}

void IULayer::setWindowController(IUWindowController* w)
{
    if (!w)
        return;
    _windowController = w;
    for (IULayer* v : _subviews) {
        v->setWindowController(w);
    }
}

IUWindowController* IULayer::windowController()
{
    return _windowController;
}
