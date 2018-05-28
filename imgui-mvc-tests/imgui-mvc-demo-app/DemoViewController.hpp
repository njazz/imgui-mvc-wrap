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

class DemoViewController : public IUViewController {
    ZoomableView v;
public:
    DemoViewController()
    {
        v.width = 640;
        v.height = 480;
        addSubview(&v);
    }
    
    virtual void drawLayerContents() override{
//        ImGuiCe::CodeEditor();        
        // ImGui::Text("test");
    };
};

#endif /* DemoViewController_hpp */

