//

#include "IUObserver.hpp"
#include "imgui.h"
#include <cctype>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>

#ifndef UIMenuBase_hpp
#define UIMenuBase_hpp

//#include "glfw3.h"

#include "IUShortcut.hpp"

#include "IUWindowController.hpp"

class IUMenuBase {
    std::map<int, IUObserver*> _actions;
    std::map<int, IUShortcut*> _shortcuts;

public:
    std::string name;

    IUWindowController* windowController = 0;

    void shortcut(int action = 0, IUShortcut shortcut = IUShortcut::None());

    bool item(std::string name, int action = 0, IUShortcut shortcut = IUShortcut::None(), bool checked = false, bool enabled = true);

    void _itemAction(int action);

    virtual void shortcuts();
    virtual void draw();

    void menu();

    void setAction(int key, IUObserver* a) { _actions[key] = a; };
};

#endif
