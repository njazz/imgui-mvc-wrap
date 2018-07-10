//
//  IUWindowController.hpp
//  imguiController
//
//  Created by Alex on 22/03/2018.
//

#ifndef IUWindowController_hpp
#define IUWindowController_hpp

#include <stdio.h>
#include <vector>

#include "imgui.h"

//#include "gl3w.h"
//#include "glfw3.h"

#include "IUView.hpp"
#include "IUViewController.hpp"

#include "IUImplementation.hpp"

#include <string>

#include "imguidock.h"

class IUWindowController {
    IUImplementation core;

    IUViewControllerBase* _viewController = 0;

    static void _errorCallback(int error, const char* description);

    void _prepareRender();
    void _drawAll();
    void _render();

    int _initWindow();
    void _freeWindow();

    std::string _title = "Window";

//    ImGuiContext* _context = 0;
    
    ImGui::DockContext* _dockContext = 0;

public:
    IUWindowController(IUViewControllerBase* vc = 0, std::string title = "Window", int x = -1, int y = -1, int width = 1280, int height = 720);
    ~IUWindowController();

    void setViewController(IUViewControllerBase* vc);
    IUViewControllerBase* viewController() { return _viewController; }

//    GLFWwindow* glWindow;
    ImVec4 clearColor = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    void setTitle(std::string t);
    std::string title() { return _title; }

    int x;
    int y;

    int width;
    int height;

    // ---

    void draw();
    void resize();

    // ---
    void restoreContext();

    // temporary fix for multiple windows / text input
    bool isEditingText = false;
    bool pollEvents = true;
    
    bool windowShouldClose(){
        return glfwWindowShouldClose(core.glWindow);
    }
    void close()
    {
        glfwSetWindowShouldClose(core.glWindow, true);
    }
    
    
};
#endif /* IUWindowController_hpp */
