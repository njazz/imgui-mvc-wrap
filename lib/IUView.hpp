//
//  IUView.hpp
//  imguiController
//
//  Created by Alex on 22/03/2018.
//

#ifndef IUView_hpp
#define IUView_hpp

#include <map>
#include <stdio.h>
#include <vector>

#include "IUAction.hpp"

#include "IULayer.hpp"

#include "imgui.h"

#include <string>

class IUWindowController;
class IUMenuBase;

// imgui "child frame"
class IUView : public IULayer {

    std::map<int, std::vector<IUAction*> > _actions;

    bool _mouseDownFlag = false;

protected:
    bool _hovered = false;

    inline bool _isMouseDown()
    {
        bool ret = (ImGui::IsMouseClicked(0) && ImGui::IsMouseHoveringRect(ImVec2(x, y), ImVec2(x + width, y + height)));
        if (ret)
            _mouseDownFlag = true;
        return ret;
    }
    inline bool _isMouseHover() { return ImGui::IsMouseHoveringRect(ImVec2(x, y), ImVec2(x + width, y + height)); }
    inline bool _isMouseReleased()
    {
        bool ret = ImGui::IsMouseReleased(0) && _mouseDownFlag;
        if (ret)
            _mouseDownFlag = false;
        return ret;
    }
    inline bool _isMouseDragged() { return ImGui::IsMouseDragging() && _mouseDownFlag; }

    //
    virtual void _handleMouse();

public:
    IUView();

    IUMenuBase* contextMenu = 0;

    float alpha = 0.75;

    void addAction(int k, IUAction* o);
    void removeAction(int k, IUAction* o);
    void removeAllActions(int k);
    void updated(int key);
    //---

    void removeFromParentView();

    virtual void draw() override;

    bool mouseEnabled = true;

    virtual void onMouseDown(ImVec2 pos){};
    virtual void onMouseHover(ImVec2 pos)
    {
        _hovered = true;
    };
    virtual void onMouseExit(ImVec2 pos)
    {
        _hovered = false;
    };
    virtual void onMouseUp(ImVec2 pos){};
    virtual void onMouseDrag(ImVec2 pos){};

    virtual void onMouseDoubleClick(ImVec2 pos){};
    virtual void onMouseRightClick(ImVec2 pos){};

    //
    void addSubview(IUView* v);
    void removeSubview(IUView* v);
    void removeAllSubviews();
};

#endif /* IUView_hpp */
