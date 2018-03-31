//
//  demoController.hpp
//  imguiController
//
//  Created by Alex on 22/03/2018.
//

#ifndef demoController_hpp
#define demoController_hpp

#include <stdio.h>

#include "imgui.h"
#include "imgui_impl_glfw_gl3.h"
#include "gl3w.h"
#include "glfw3.h"

//#include "SingleWindowController.hpp"
#include "IUView.hpp"

class DemoViews : public IUView {
    bool _demoWindow = false;
    bool _anotherWindow = false;

public:
    virtual void draw() override
    {

        // 1. Show a simple window.
        // Tip: if we don't call ImGui::Begin()/ImGui::End() the widgets automatically appears in a window called "Debug".
        
        ImGui::SetNextWindowPos(ImVec2(650, 220), ImGuiCond_FirstUseEver);
        {
            ImGui::Begin("Debug");
            static float f = 0.0f;
            static int counter = 0;
            ImGui::Text("Hello, world!"); // Display some text (you can use a format string too)
            ImGui::SliderFloat("float", &f, 0.0f, 1.0f); // Edit 1 float using a slider from 0.0f to 1.0f
            //ImGui::ColorEdit3("clear color", (float*)window::clear_color); // Edit 3 floats representing a color

            ImGui::Checkbox("Demo Window", &_demoWindow); // Edit bools storing our windows open/close state
            ImGui::Checkbox("Another Window", &_anotherWindow);

            if (ImGui::Button("Button")) // Buttons return true when clicked (NB: most widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::End();
        }

        // 2. Show another simple window. In most cases you will use an explicit Begin/End pair to name your windows.
        if (_anotherWindow) {
            ImGui::Begin("Another Window", &_anotherWindow);
            ImGui::Text("Hello from another window!");
            if (ImGui::Button("Close Me"))
                _anotherWindow = false;
            ImGui::End();
        }

        // 3. Show the ImGui demo window. Most of the sample code is in ImGui::ShowDemoWindow(). Read its code to learn more about Dear ImGui!
        if (_demoWindow) {
            ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiCond_FirstUseEver); // Normally user code doesn't need/want to call this because positions are saved in .ini file anyway. Here we just want to make the demo initial state a bit more friendly!
            ImGui::ShowDemoWindow(&_demoWindow);
        }
    }
};

#endif /* demoController_hpp */




