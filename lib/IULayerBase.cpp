//
//  IUSubLayer.cpp
//  nseq
//
//  Created by Alex on 28/03/2018.
//  Copyright © 2018 Alex Nadzharov. All rights reserved.
//

#include "IULayerBase.hpp"

IULayerBase::IULayerBase()
{
    idString = "SL" + std::to_string((long)this);
}

//void IUSubLayer::draw()
//{
//    ImGui::BeginChild(ImGui::GetID(idString.c_str()));
//    if (!hidden)
//        drawLayerContents();
//    ImGui::EndChild();
//};
