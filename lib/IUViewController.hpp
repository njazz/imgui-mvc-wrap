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

//#include "IUMainMenuBase.hpp"

// imgui "window"
class IUViewController : public IUView {
    friend class IUWindowController;

    std::vector<IUViewController*>_subControllers;
public:
    IUViewController()
    {
        flags = flags | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoTitleBar;
    }

    std::string title = "";
    ImGuiWindowFlags flags = ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoFocusOnAppearing; // | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoBringToFrontOnFocus
    bool display = true;    // todo property


    virtual void setWindowController(IUWindowController* w) override;

    // test:
    void addSubcontroller(IUViewController* v)
    {
        v->_parent = this;
        _subControllers.push_back(v);
    }

    // IoC - later
    //    virtual void showViewController(){};
    //    virtual void hideViewController(){};

    virtual void draw() override;
    virtual void drawMenu();

    IUMainMenuBase* menu = 0;
};
#endif /* IUViewController_hpp */
