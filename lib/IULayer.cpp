//
//  IULayer.cpp
//  nseq
//
//  Created by Alex on 28/03/2018.
//  Copyright © 2018 Alex Nadzharov. All rights reserved.
//

#include "IULayer.hpp"

#include "IUWindowController.hpp"

void IULayer::draw()
{
    if (hidden)
        return;
    _drawSubviews();
};

void IULayer::_drawSubviews()
{
    ImVec2 offset = ImGui::GetCursorScreenPos();
    //printf("offset %f %f\n", offset.x,offset.y);
    
    for (int i=0;i<_subviews.size();i++)
    {
        _subviews[i]->offset = offset;
        _subviews[i]->draw();
    }
};

void IULayer::addSubview(IULayer* v)
{
    _subviews.push_back(v);
    v->_parent = this;
    v->setWindowController(_windowController);
}

void IULayer::removeAllSubviews()
{
    for (IULayer* d : _subviews)
        d->_parent = 0;

    _subviews.clear();
}

void IULayer::setWindowController(IUWindowController* w)
{
    _windowController = w;
    for (IULayer* v : _subviews) {
        v->setWindowController(w);
    }
}
IUWindowController* IULayer::windowController() { return _windowController; }
