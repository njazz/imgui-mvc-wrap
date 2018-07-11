//
//  IUBase.cpp
//  imgui-lib
//
//  Created by Alex on 09/07/2018.
//  Copyright © 2018 Alex Nadzharov. All rights reserved.
//

#include "IUBase.hpp"

void IUBase::setWindowController(IUWindowController* w)
{
    _windowController = w;
}
IUWindowController* IUBase::windowController() { return _windowController; }
