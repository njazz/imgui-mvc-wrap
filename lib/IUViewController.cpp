//
//  IUViewController.cpp
//  imguiController
//
//  Created by Alex on 22/03/2018.
//

#include "IUViewController.hpp"
#include "IUWindowController.hpp"

void IUViewController::setWindowController(IUWindowController* w)
{
    IUView::setWindowController(w);
    showViewController();
}
