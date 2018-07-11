//

#include "IUMenuBase.hpp"
#include "IUWindowController.hpp"

void IUMenuBase::shortcut(int action, IUShortcut shortcut)
{
    if (shortcut.keyPressed())
        _itemAction(action);
}

void IUMenuBase::_itemAction(int action)
{
    if (action) {
        if (_actions[action]) {
            _actions[action]->action();
            if (_windowController)
                _windowController->restoreContext();
        }
    }
}

// ---

bool IUMenuBase::item(std::string name, int action, IUShortcut shortcut, bool checked, bool enabled)
{
    if (ImGui::MenuItem(name.c_str(), shortcut.str().c_str(), checked, enabled)) {

        _itemAction(action);
//        if (_windowController)
//            _windowController->restoreContext();
        return true;
    }
    return false;
}



//void IUMenuBase::shortcuts(){};
// void IUMenuBase::draw(){};

void IUMenuBase::draw()
{
//    float fontScale = ImGui::GetCurrentWindow()->FontWindowScale;
//    ImGui::SetWindowFontScale(1);

    shortcuts();

    if (ImGui::BeginMenu(name.c_str())) {
        _drawComponents();
        _drawContents();
        ImGui::EndMenu();
    }

//    ImGui::SetWindowFontScale(fontScale);
}

//void IUMenuBase::shortcuts()
//{
//    for (auto s:_shortcuts)
//    {}
//}

