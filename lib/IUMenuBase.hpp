//

#include "IUAction.hpp"
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

#include "IUBase.hpp"

class IUMenuBase : public IUBaseT<IUMenuBase> {
    std::map<int, IUAction*> _actions;
    std::map<int, IUShortcut*> _shortcuts;

public:
    std::string name;

//    IUWindowController* windowController = 0;

    void shortcut(int action = 0, IUShortcut shortcut = IUShortcut::None());

    bool item(std::string name, int action = 0, IUShortcut shortcut = IUShortcut::None(), bool checked = false, bool enabled = true);

    void _itemAction(int action);

    virtual void draw() override;
    virtual void drawContents() override {};

    void setAction(int key, IUAction* a) { _actions[key] = a; };

    // todo: better way
    void copyActionsFrom(IUMenuBase* src)
    {
        _actions = src->_actions;
        _shortcuts = src->_shortcuts;
    }
    
//    virtual void shortcuts() override;
    
};

#endif
