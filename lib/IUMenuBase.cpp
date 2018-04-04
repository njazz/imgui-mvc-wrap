//

#include "IUMenuBase.hpp"
#include "IUWindowController.hpp"

void IUMenuBase::shortcut(int action, IUShortcut shortcut)
{
    if (shortcut.keyPressed())
        _itemAction(action);
}

bool IUMenuBase::item(std::string name, int action, IUShortcut shortcut, bool checked, bool enabled)
{
    if (ImGui::MenuItem(name.c_str(), shortcut.str().c_str(), checked, enabled)) {

        _itemAction(action);
        return true;
    }
    return false;
}

void IUMenuBase::_itemAction(int action)
{
    if (action) {
        if (_actions[action]) {
            _actions[action]->updated();
            if (windowController)
                windowController->restoreContext();
        }
    }
}

 void IUMenuBase::shortcuts(){};
 void IUMenuBase::draw(){};

void IUMenuBase::menu()
{

    shortcuts();

    if (ImGui::BeginMenu(name.c_str())) {
        draw();
        ImGui::EndMenu();
    }
}
