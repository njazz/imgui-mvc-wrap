//
//  IUImplementation.hpp
//  nseq
//
//  Created by Alex on 28/03/2018.
//  Copyright © 2018 Alex Nadzharov. All rights reserved.
//

#ifndef IUImplementation_hpp
#define IUImplementation_hpp

#include <stdio.h>

#include "imgui.h"
//struct GLFWwindow;

#include "glcorearb.h"

#define GL_ARB_shader_objects
// GL3W/GLFW
#include "gl3w.h" // This example is using gl3w to access OpenGL functions (because it is small). You may use glew/glad/glLoadGen/etc. whatever already works for you.
#include "glfw3.h"

#ifdef _WIN32
#undef APIENTRY
#define GLFW_EXPOSE_NATIVE_WIN32
#define GLFW_EXPOSE_NATIVE_WGL
#include <GLFW/glfw3native.h>
#endif

#include <map>

class IUImplementation {
    // GLFW data
    GLFWwindow* g_Window = NULL;
    double g_Time = 0.0f;
    //    bool g_MouseJustPressed[3] = { false, false, false };
    GLFWcursor* g_MouseCursors[ImGuiMouseCursor_COUNT] = { 0 };

    // OpenGL3 data
    char g_GlslVersion[32] = "#version 150";
    GLuint g_FontTexture = 0;
    int g_ShaderHandle = 0, g_VertHandle = 0, g_FragHandle = 0;
    int g_AttribLocationTex = 0, g_AttribLocationProjMtx = 0;
    int g_AttribLocationPosition = 0, g_AttribLocationUV = 0, g_AttribLocationColor = 0;
    unsigned int g_VboHandle = 0, g_ElementsHandle = 0;

    //
    static std::map<GLFWwindow*, bool[3]> g_mousePressed;

    // ---

    void _renderDrawData(ImDrawData* draw_data);

    static void _mouseButtonCallback(GLFWwindow*, int button, int action, int /*mods*/);
    static void _scrollCallback(GLFWwindow*, double xoffset, double yoffset);
    static void _keyCallback(GLFWwindow*, int key, int, int action, int mods);
    static void _charCallback(GLFWwindow*, unsigned int c);

    bool _createFontsTexture();
    bool _createDeviceObjects();

    void _invalidateDeviceObjects();

    void _installCallbacks(GLFWwindow* window);

public:
    bool init(GLFWwindow* window, bool install_callbacks, const char* glsl_version = NULL);
    void shutdown();

    void newFrame();
    void renderDrawData(ImDrawData* draw_data);

    // Use if you want to reset your rendering device without losing ImGui state.
    void invalidateDeviceObjects();
    bool createDeviceObjects();

    //
    void switchContext(GLFWwindow* window, ImGuiContext* ctx);
};

#endif /* IUImplementation_hpp */
