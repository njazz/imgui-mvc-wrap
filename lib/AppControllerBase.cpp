
//
//  AppController.cpp
//  imguiController
//
//  Created by Alex on 22/03/2018.
//

#include "AppControllerBase.hpp"

//#include "glfw3.h"
#include "IUViewController.hpp"
#include "IUWindowController.hpp"

#include <algorithm>
#include <fstream>
#include <string>

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

//

ImFont *AppControllerBase::addFont(std::string font)
{
    ImFont* ret = 0;

    ImGuiIO& io = ImGui::GetIO();

    std::ifstream fontfile(font);

    if (fontfile.good()) {
        ret = io.Fonts->AddFontFromFileTTF(font.c_str(), 32.0f, NULL, io.Fonts->GetGlyphRangesCyrillic());
        return ret;
    } else {
        printf("font file not found!\n");
        return ret;
    }
}
