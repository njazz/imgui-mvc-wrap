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


class IUWindowController;

// base class
class IULayerBase {

public:
    IULayerBase();

    std::string idString;

    virtual void drawLayerContents(){};

    float x = 0;
    float y = 0;
    float width = 0;
    float height = 0;

    bool hidden = false;

    ImVec2 size();
    ImVec2 pos();
    
    inline float scale();
    
    bool zoomable = true;
};

#endif /* IUSubLayer_hpp */
