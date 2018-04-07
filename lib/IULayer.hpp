//
//  IULayer.hpp
//  nseq
//
//  Created by Alex on 28/03/2018.
//  Copyright © 2018 Alex Nadzharov. All rights reserved.
//

#ifndef IULayer_hpp
#define IULayer_hpp

#include <stdio.h>

#include <string>
#include <vector>

#include "IULayerBase.hpp"
#include "imgui.h"

class IUWindowController;

// imgui child frame
class IULayer : public IULayerBase {
protected:
    std::vector<IULayer*> _subviews;
    void _drawSubviews();

    IULayer* _parent = 0;
    IUWindowController* _windowController = 0;

    ImVec2 _getContentSize()
    {
        return ImVec2(contentSize.x < width ? width : contentSize.x, contentSize.y < height ? height : contentSize.y);
    }

    void _setBounds();

public:
    bool manualLayout = false;

    float padding = 0;

    IULayer();

    virtual void draw();

    void addSubview(IULayer* v);
    void removeSubview(IULayer* v);
    void removeAllSubviews();

    virtual void setWindowController(IUWindowController* w);
    IUWindowController* windowController();

    //
    ImVec2 offset = ImVec2(0, 0);
    ImVec2 contentSize = ImVec2(0, 0);

    ImVec2 positionInParent()
    {
        if (!_parent)
            return pos();

        return ImVec2(x + offset.x, y + offset.y);
    }
    void updateOffset() { offset = ImGui::GetCursorScreenPos(); }
};

#endif /* IULayer_hpp */
