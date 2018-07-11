//
//  IUViewController.hpp
//  imguiController
//
//  Created by Alex on 22/03/2018.
//

#ifndef IUViewController_hpp
#define IUViewController_hpp

#include <stdio.h>
#include <vector>

class IUWindowController;
class IUMainMenuBase;

#include "IUView.hpp"

// new
#include "imguidock.h"

// imgui "window"
class IUViewControllerBase : public IUView {
    friend class IUWindowController;

    //    std::vector<IUViewControllerBase*> _subControllers;

protected:
    //    void _drawSubcontrollers()
    //    {
    //        for (auto s : _subControllers)
    //            if (!s->hidden)
    //                s->draw();

    //        // ?
    //        //    if (_subControllers.size())
    //        //        return;
    //    }

public:
    IUViewControllerBase()
    {
        idString = "VC" + std::to_string((long)this);
        flags = ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize  | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoTitleBar;

        zoomable = false;
    }

    std::string title = "";
//    ImGuiWindowFlags flags = ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoFocusOnAppearing; // | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoBringToFrontOnFocus

    //    bool display = true; // todo property

    //    virtual void setWindowController(IUWindowController* w) override;

    // test:

    // IoC - later
    //    virtual void showViewController(){};
    //    virtual void hideViewController(){};

    virtual void draw() override;

    // todo: non virtual
    virtual void drawMenu();

    IUMainMenuBase* menu = 0;

    //    bool dockable = false;
    //    bool dockSpace = false;
};

//
class IUViewController : public IUViewControllerBase {
};

//
class IUViewContainer : public IUViewControllerBase {
private:
    void addSubview(IUView* v);
    void removeSubview(IUView* v);
    void removeAllSubviews(IUView* v);

public:
    void addSubcontroller(IUViewControllerBase* v)
    {
        if (!v)
            return;
        v->_parent = this;

        addComponent(v);
    }

    virtual void draw() override
    {
        drawMenu();

        //_drawSubcontrollers();

        //        // setup
        //        ImGui::SetNextWindowPos(pos());
        //        //if (flags & !ImGuiWindowFlags_NoResize)
        //        ImGui::SetNextWindowSize(size(), ImGuiCond_Always);
        //        ImGui::SetNextWindowContentSize(_getContentSize());
        //
        //        // draw
        //        auto wp = ImGui::GetStyle().WindowPadding;
        //        auto fp = ImGui::GetStyle().FramePadding;
        //        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(padding, padding));
        //        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(padding, padding));
        //
        //        //    if (dockable)
        //        //        ImGui::BeginDock(title.c_str(), &display, flags);
        //        //    else
        //        ImGui::Begin(title.c_str(), &display, ImVec2(0, 0), alpha, flags);
        //
        //        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, wp);
        //        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, fp);

        //    _drawAllContents();

        //        _drawContents();
        _drawComponents();
        //        _shortcutContents();
        _shortcutComponents();
//        _handleMouse();
        //    _shortcutComponents();

        //        ImGui::PopStyleVar();
        //        ImGui::PopStyleVar();

        //    if (dockable)
        //        ImGui::EndDock();
        //    else
        //        ImGui::End();
        //
        //        ImGui::PopStyleVar();
        //        ImGui::PopStyleVar();
    }
};

#endif /* IUViewController_hpp */


