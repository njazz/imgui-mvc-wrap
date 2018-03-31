//

#include "IUObserver.hpp"
#include "imgui.h"
#include <map>
#include <string>

#ifndef UIMenuBase_hpp
#define UIMenuBase_hpp

#include "IUWindowController.hpp"


class IUKey {
    std::string _string;
    int _keyCode = 0;


public:
    IUKey(std::string s, int keyCode)
    {
        _string = s;
        _keyCode = keyCode;
    };

    std::string str() { return _string; }
    int key() { return _keyCode; }

    static IUKey None() { return IUKey("", 0); }
    static IUKey Ctrl() { return IUKey("Ctrl", 0); }
    static IUKey Action()
    {
        // osx
        return IUKey("Cmd", 0);
        // else
        // return IUKey("Ctrl", 0);
    }
    static IUKey Shift() { return IUKey("Shift", 0); }
    static IUKey Alt() { return IUKey("Alt", 0); }

    static IUKey C(char ch) {return IUKey(std::string(1,ch),0);}


};

IUKey operator+(IUKey a, IUKey b);


class IUMenuBase {
    std::map<int, IUObserver*> _actions;

public:
    std::string name;

    IUWindowController* windowController = 0;

    void item(std::string name, int action = 0, IUKey shortcut = IUKey::None(), bool checked = false, bool enabled = true)
    {
        if (ImGui::MenuItem(name.c_str(), shortcut.str().c_str(), checked, enabled)) {
            if (action) {
                if (_actions[action]) {
                    _actions[action]->updated();
                    if (windowController)
                        windowController->restoreContext();
                }
            }
        }
    }

    virtual void draw(){};

    void menu()
    {
        if (ImGui::BeginMenu(name.c_str())) {
            draw();
            ImGui::EndMenu();
        }
    }

    void setAction(int key, IUObserver* a) { _actions[key] = a; };
};

#endif
