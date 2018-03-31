//
//  DemoView.hpp
//  imguiController
//
//  Created by Alex on 22/03/2018.
//

#ifndef DemoView_hpp
#define DemoView_hpp

#include <stdio.h>

#include "IUView.hpp"
#include "imgui.h"
//#include "SingleWindowController.hpp"

float _setter(void* f, int idx);

class WidgetTestViewCallback {
public:
    virtual void wtvCallback(){};
};

class WidgetTestView : public IUView {

public:
    WidgetTestViewCallback* t = 0;

    static float _array[16];
    virtual void draw() override
    {
        
        ImGui::SetNextWindowSize(ImVec2(300, 640));  //ImGuiCond_FirstUseEver
        ImGui::SetNextWindowPos(ImVec2(300, 0), ImGuiCond_FirstUseEver);
        ImGui::Begin("Widget test");

        ImGui::PlotHistogram("test1",  _array, 16);

        if (ImGui::Button("test")) {
            updated();
        };

        ImGui::End();
    };
};

#endif /* DemoView_hpp */


