//
//  IUViewController.hpp
//  imguiController
//
//  Created by Alex on 22/03/2018.
//

#ifndef IUDockController_hpp
#define IUDockController_hpp

#include <stdio.h>
#include <vector>

#include "IUViewController.hpp"



class IUDockableViewController : public IUViewControllerBase {
public:
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

//        _drawAllContents();

        _drawComponents();
        _shortcutContents();
        _shortcutComponents();
        _handleMouse();


        ImGui::PopStyleVar();
        ImGui::PopStyleVar();

        ImGui::EndDock();

        ImGui::PopStyleVar();
        ImGui::PopStyleVar();
    }
};

class IUDockViewController : public IUViewControllerBase {
public:
    IUDockViewController()
        : IUViewControllerBase()
    {
        auto d_c = ImGui::CreateDockContext();
        ImGui::SetCurrentDockContext(d_c);
    }
    virtual void draw() override
    {
        drawMenu();

        ImGui::SetNextWindowPos(pos());
        ImGui::SetNextWindowSize(size(), ImGuiCond_Always);
        ImGui::SetNextWindowContentSize(_getContentSize());

        bool w = true;
        ImGui::Begin("", &w, flags);

        ImGui::BeginDockspace();

        //_drawSubcontrollers();
//        _drawComponents();
        _drawAllContents();
        _shortcutContents();
        _shortcutComponents();

        ImGui::EndDockspace();
        ImGui::End();
    }
    
    void addSubcontroller(IUDockableViewController*d)
    {
        addComponent(d);
    }
};

#endif /* IUViewController_hpp */
