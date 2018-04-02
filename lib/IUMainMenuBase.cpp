//

#include "IUMainMenuBase.hpp"

void IUMainMenuBase::draw()
{
    ImGui::BeginMainMenuBar();

    for (auto s : _menus)
        s->menu();

    ImGui::EndMainMenuBar();
}

void IUMainMenuBase::addMenu(IUMenuBase* m, std::string name)
{
    m->name = name;
    m->windowController = _windowController;
    _menus.push_back(m);
}

void IUMainMenuBase::setWindowController(IUWindowController* w)
{
    _windowController = w;
    for (auto m : _menus)
        m->windowController = _windowController;
}
