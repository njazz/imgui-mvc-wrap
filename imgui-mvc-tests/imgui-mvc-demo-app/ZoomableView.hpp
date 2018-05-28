//
//  ZoomableView.hpp
//  imgui-mvc-demo-app
//
//  Created by Alex on 28/05/2018.
//

#ifndef ZoomableView_hpp
#define ZoomableView_hpp

#include <stdio.h>

#include "IUView.hpp"

#include "TestObject.hpp"

class ZoomableView : public IUView {
public:
    ZoomableView()
    {
        manualLayout = true;
        zoomable = true;
        
        TestObject* o = new TestObject;
        o->x = 100;
        o->y = 100;
        o->width = 150;
        o->height = 30;

        o->manualLayout = true;

        addSubview(o);

        o = new TestObject;
        o->x = 300;
        o->y = 100;
        o->width = 150;
        o->height = 30;

        o->manualLayout = true;

        addSubview(o);

        o = new TestObject;
        o->x = 200;
        o->y = 300;
        o->width = 150;
        o->height = 30;

        o->manualLayout = true;

        addSubview(o);
    }

    virtual void drawLayerContents() override
    {
        
        ImGui::Text("Font scale: %f",ImGui::GetCurrentWindow()->FontWindowScale);
        ImGui::SliderFloat("Scale", &ImGui::GetCurrentWindow()->FontWindowScale, .25, 2.);
        
    }
};

#endif /* ZoomableView_hpp */
