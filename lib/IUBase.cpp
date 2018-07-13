//
//  IUBase.cpp
//  imgui-lib
//
//  Created by Alex on 09/07/2018.
//  Copyright © 2018 Alex Nadzharov. All rights reserved.
//

#include "IUBase.hpp"

#include "imgui.h"

#include <algorithm>

void IUBase::setWindowController(IUWindowController* w)
{
    _windowController = w;
}
IUWindowController* IUBase::windowController() { return _windowController; }

void IUBase::_acceptKeyboard()
{

}

void IUBase::_acceptMouse()
{
    ImGui::GetIO().MouseDown[0] = false;
    ImGui::GetIO().MouseDown[1] = false;

    ImGui::GetIO().MouseClicked[0] = false;
    ImGui::GetIO().MouseClicked[1] = false;

    ImGui::GetIO().MouseDownDuration[0] = 1.;
    ImGui::GetIO().MouseDownDuration[1] = 1.;


}
