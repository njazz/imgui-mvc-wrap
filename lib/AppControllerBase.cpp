
//
//  AppController.cpp
//  imguiController
//
//  Created by Alex on 22/03/2018.
//

#include "AppControllerBase.hpp"

//#include "glfw3.h"
#include "IUWindowController.hpp"
#include "IUViewController.hpp"

void AppControllerBase::_windowDrawLoop()
{
    while (_windowControllers.size()) {

        // text edit workaround
        bool textEditFix = false;
        for (int i = 0; i < _windowControllers.size(); i++) {
            auto w = _windowControllers[i];
            if (w->isEditingText)
                textEditFix = true;
        }

        for (int i = 0; i < _windowControllers.size(); i++) {
            auto w = _windowControllers[i];
            // textedit fix

            w->pollEvents = (textEditFix) ? w->isEditingText : true;
            w->draw();
        }

        // close windows
        int i = 0;
        while (i < _windowControllers.size()) {

            auto w = _windowControllers[i];

            if (w->windowShouldClose()) {

                //removeWindow(w);
                delete w;
                _windowControllers.erase(_windowControllers.begin() + i);

            } else
                i++;
        }
    }
}

void AppControllerBase::runLoop()
{
    _windowDrawLoop();
}

void AppControllerBase::addWindow(IUWindowController* w)
{
    _windowControllers.push_back(w);
}

void AppControllerBase::removeWindow(IUWindowController* w)
{
    auto ww = std::find(_windowControllers.begin(), _windowControllers.end(), w);
    if (ww != _windowControllers.end()) {
        _windowControllers.erase(ww);
        delete w;
    }
}

IUWindowController* AppControllerBase::windowAt(int i)
{
    if (i >= _windowControllers.size())
        return 0;

    return _windowControllers[i];
}

AppControllerBase::~AppControllerBase()
{
    glfwTerminate();
}
