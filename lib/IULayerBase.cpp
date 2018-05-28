//
//  IUSubLayer.cpp
//  nseq
//
//  Created by Alex on 28/03/2018.
//  Copyright © 2018 Alex Nadzharov. All rights reserved.
//

#include "IULayerBase.hpp"

#include "imgui_internal.h"

IULayerBase::IULayerBase()
{
    idString = "SL" + std::to_string((long)this);
}

ImVec2 IULayerBase::size()
{
    return ImVec2(width * scale(), height * scale());
};

ImVec2 IULayerBase::pos()
{
    return ImVec2(x * scale(), y * scale());
};

inline float IULayerBase::scale()
{
    //return 1;
    return (zoomable) ? ImGui::GetCurrentWindow()->FontWindowScale : 1;
}

//void IUSubLayer::draw()
//{
//    ImGui::BeginChild(ImGui::GetID(idString.c_str()));
//    if (!hidden)
//        drawLayerContents();
//    ImGui::EndChild();
//};
