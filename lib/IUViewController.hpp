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

//#include "IUMainMenuBase.hpp"

// imgui "window"
class IUViewControllerBase : public IUView {
    friend class IUWindowController;

    std::vector<IUViewControllerBase*> _subControllers;

protected:
    void _drawSubcontrollers()
    {
        for (auto s : _subControllers)
            if (!s->hidden)
                s->draw();

        // ?
        //    if (_subControllers.size())
        //        return;
    }

public:
    IUViewControllerBase()
    {
        idString = "VC" + std::to_string((long)this);
        flags = flags | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoTitleBar;

        zoomable = false;
    }

    std::string title = "";
    ImGuiWindowFlags flags = ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoFocusOnAppearing; // | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoBringToFrontOnFocus
    bool display = true; // todo property

    virtual void setWindowController(IUWindowController* w) override;

    // test:
    void addSubcontroller(IUViewControllerBase* v)
    {
        if (!v)
            return;
        v->_parent = this;
        _subControllers.push_back(v);
    }

    // IoC - later
    //    virtual void showViewController(){};
    //    virtual void hideViewController(){};

    virtual void draw() override;
    virtual void drawMenu();

    IUMainMenuBase* menu = 0;

    //    bool dockable = false;
    //    bool dockSpace = false;
};

//
class IUViewController : public IUViewControllerBase {
};

class IUDockableViewController : public IUViewControllerBase {
    virtual void draw() override
    {

        // setup
        //        ImGui::SetNextWindowPos(pos());
        //        //        if (flags & !ImGuiWindowFlags_NoResize)
        //        ImGui::SetNextWindowSize(size(), ImGuiCond_Always);
        //        ImGui::SetNextWindowContentSize(_getContentSize());

        // draw
        auto wp = ImGui::GetStyle().WindowPadding;
        auto fp = ImGui::GetStyle().FramePadding;
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(padding, padding));
        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(padding, padding));

        bool d = true;
        ImGui::BeginDock(title.c_str(), &d);

        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, wp);
        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, fp);

        _drawAllContents();
        _handleMouse();
        _shortcutComponents();

        ImGui::PopStyleVar();
        ImGui::PopStyleVar();

        ImGui::EndDock();

        ImGui::PopStyleVar();
        ImGui::PopStyleVar();
    }
};

class IUDockViewController : public IUViewControllerBase {
public:
    virtual void draw() override
    {
        drawMenu();

        ImGui::SetNextWindowPos(pos());
        ImGui::SetNextWindowSize(size(), ImGuiCond_Always);
        ImGui::SetNextWindowContentSize(_getContentSize());

        bool w = true;
        ImGui::Begin("", &w, flags);

        ImGui::BeginDockspace();

        _drawSubcontrollers();
        _drawAllContents();
        _shortcutComponents();

        ImGui::EndDockspace();
        ImGui::End();
    }
};

#endif /* IUViewController_hpp */

/



