
//
//  AppController.hpp
//  imguiController
//
//  Created by Alex on 22/03/2018.
//

#ifndef AppControllerBase_hpp
#define AppControllerBase_hpp

#include <stdio.h>
#include <vector>

class IUWindowController;

class AppControllerBase {
protected:
    std::vector<IUWindowController*> _windowControllers;

public:
    ~AppControllerBase();

    void _windowDrawLoop();

    void runLoop();

    void addWindow(IUWindowController* w);
    void removeWindow(IUWindowController* w);

    IUWindowController* windowAt(int i);
};

#endif /* AppController_hpp */
