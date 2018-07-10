//
//  DemoViewController.hpp
//  imgui-mvc-demo-app
//
//  Created by Alex on 28/05/2018.
//

#ifndef DemoViewController_hpp
#define DemoViewController_hpp

#include <stdio.h>

#include "IUViewController.hpp"

#include "imguicodeeditor.h"

#include "ZoomableView.hpp"

#include "imguidock.h"

class DemoViewController : public IUDockViewController {
    
    
    //    ZoomableView v;
    
    //IUDockViewController _dock;
    IUDockableViewController _vc1;
    IUDockableViewController _vc2;
public:
    DemoViewController()
    {
        //        v.width = 640;
        //        v.height = 480;
        //        addSubview(&v);

        auto d_c = ImGui::CreateDockContext();
        ImGui::SetCurrentDockContext(d_c);
        
        _vc1.title = "dock 1";
        _vc2.title = "dock 2";
        
        addSubcontroller(&_vc1);
        addSubcontroller(&_vc2);
        
    }

//    virtual void draw() override
//    {
//
//        ImGui::BeginDockspace();
//
//        bool b1 = true;
//        ImGui::BeginDock("dock 1", &b1);
//        ImGui::EndDock();
//
//        ImGui::BeginDock("dock 2");
//        ImGui::EndDock();
////
//        ImGui::EndDockspace();
//    };
};

#endif /* DemoViewController_hpp */
