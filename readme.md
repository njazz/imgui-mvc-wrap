## dear imgui, + GLFW + GL3W MVC-like application library

Currently this is a pert of tilde~/imgui project - a new integrated IDE for PureData visual programming language for multimedia.

Small application framework following MVC-like pattern
Based on "dear imgui," library: https://github.com/ocornut/imgui

Dependencies:
- GLFW library

Usage:
- Implement "AppController" class deriving from AppControllerBase

Classes:
- AppControllerBase. Implements main runloop, and allows to add/remove windows.
- IUWindowController. Shows window that includes IUViewController.
- IUViewController. Base controller class that includes single IUView.
- IULayer. Base wrapper class. Override draw() for custom draw commands.
- IUView. Base class that includes IUView and IUObservers
- IUObserver. Callback interface class.
- IUMainMenuBase. Base class for main window menu.
- IUMenuBase. Wrapper for menu.
