//
//  DemoAppController.hpp
//  imgui-mvc-demo-app
//
//  Created by Alex on 28/05/2018.
//

#ifndef DemoAppController_hpp
#define DemoAppController_hpp

#include <stdio.h>

#include "AppControllerBase.hpp"
#include "IUWindowController.hpp"
#include "DemoViewController.hpp"

class AppController : public AppControllerBase
{
public:
    AppController(){
        addWindow(new IUWindowController(new DemoViewController, "Demo App", 100, 100));
    }
};

#endif /* DemoAppController_hpp */
