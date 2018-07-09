//
#include "IUMainMenuBase.hpp"

void IUMainMenuBase::draw()
{
    ImGui::BeginMainMenuBar();

    _drawComponents();

    ImGui::EndMainMenuBar();
}

void IUMainMenuBase::addMenu(IUMenuBase* m, std::string name)
{
    m->name = name;
    addComponent(m);
}


