//
//  IULayer.hpp
//  nseq
//
//  Created by Alex on 28/03/2018.
//  Copyright © 2018 Alex Nadzharov. All rights reserved.
//

#ifndef IUSubLayer_hpp
#define IUSubLayer_hpp

#include <stdio.h>

#include <string>
#include <vector>

#include "imgui.h"
#include "imgui_internal.h"

#include "IUBase.hpp"

class IUWindowController;

// base class for layers etc
class IULayerBase : public IUBaseT<IULayerBase> {
    friend class IULayer;
protected:
    IULayerBase* _parent = 0;
    
public:
    // id
    std::string idString;
    
    IULayerBase();

    // main
//    virtual void drawLayerContents(){};

    // size
    bool manualLayout = false;
    
    float x = 0;
    float y = 0;
    float width = 0;
    float height = 0;

    bool hidden = false;

    ImVec2 size();
    ImVec2 pos();

    inline float scale() { return (zoomable) ? ImGui::GetCurrentWindow()->FontWindowScale : 1; }

    bool zoomable = true;
};

#endif /* IUSubLayer_hpp */
