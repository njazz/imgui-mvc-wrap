

//
//  IUWindowController.cpp
//  imguiController
//
//  Created by Alex on 22/03/2018.
//

#include "IUWindowController.hpp"

//#include "IUImplementation.hpp"

//IUWindowController::IUWindowController()
//{
//    _initWindow();
//}
IUWindowController::IUWindowController(IUViewController* vc, std::string title, int x, int y, int w, int h)
{
    setViewController(vc);

    width = w;
    height = h;

    _initWindow();

    setTitle(title);

    if ((x >= 0) || (y >= 0)) {
        glfwSetWindowPos(glWindow, x, y);
    }
}

IUWindowController::~IUWindowController()
{
    _freeWindow();
}

// ---
#pragma mark -

void IUWindowController::setViewController(IUViewController* vc)
{
    _viewController = vc;
    if (!vc)
        return;

    _viewController->setWindowController(this); //->windowController = this;
}

// ---
#pragma mark -

void IUWindowController::_errorCallback(int error, const char* description)
{
    fprintf(stderr, "IUWindowController error %d: %s\n", error, description);
}

// ---
#pragma mark -

int IUWindowController::_initWindow()
{
    // Setup window
    glfwSetErrorCallback(_errorCallback);

    if (!glfwInit())
        return 1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#if __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    glWindow = glfwCreateWindow(width, height, _title.c_str(), NULL, NULL);
    glfwMakeContextCurrent(glWindow);
    glfwSwapInterval(1); // Enable vsync
    gl3wInit();

    // Setup ImGui binding
    ImGui::SetCurrentContext(0);
    _context = ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();

    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;   // Enable Gamepad Controls

    core.init(glWindow, true);

    // Setup style
    //ImGui::StyleColorsDark();
    ImGui::StyleColorsClassic();
    //    ImGui::StyleColorsLight();

    // Load Fonts

    io.Fonts->AddFontFromFileTTF("../Resources/fonts/Arial-Unicode-Regular.ttf", 32.0f, NULL, io.Fonts->GetGlyphRangesCyrillic());
    io.DisplayFramebufferScale = ImVec2(2, 2);
    io.FontGlobalScale = 0.5;

    glfwSetWindowUserPointer(glWindow, (void*)this);

    return 0;
}

void IUWindowController::_freeWindow()
{

    core.switchContext(glWindow, _context);
    core.shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(glWindow);
}

// ---
#pragma mark -

void IUWindowController::_prepareRender()
{
    core.switchContext(glWindow, _context);


    if (pollEvents)
        glfwPollEvents();

    core.newFrame();

    glfwGetFramebufferSize(glWindow, &width, &height);
}

void IUWindowController::_drawAll()
{
    if (!_viewController)
        return;

    _viewController->width = width / 2;
    _viewController->height = height / 2;

    _viewController->draw();
}

void IUWindowController::_render()
{
    // Rendering
    glViewport(0, 0, width, height);
    glClearColor(clearColor.x, clearColor.y, clearColor.z, clearColor.w);
    glClear(GL_COLOR_BUFFER_BIT);

    ImGui::Render();

    core.renderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(glWindow);
}

void IUWindowController::draw()
{
    if (!glWindow)
        return;

    _prepareRender();
    _drawAll();
    _render();
}

void IUWindowController::resize()
{
    bool pe = pollEvents;
    pollEvents = false;
    draw();
    pollEvents = pe;
}

void IUWindowController::restoreContext()
{
    core.switchContext(glWindow, _context);
}

void IUWindowController::setTitle(std::string t)
{
    _title = t;
    if (glWindow)
        glfwSetWindowTitle(glWindow, _title.c_str());
}