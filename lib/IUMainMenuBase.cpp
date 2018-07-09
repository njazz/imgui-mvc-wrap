//
#include "IUMainMenuBase.hpp"

void IUMainMenuBase::draw()
{
    ImGui::BeginMainMenuBar();

    _drawComponents();
    _shortcutComponents();

    ImGui::EndMainMenuBar();
    
//    _updateComponents();

}

void IUMainMenuBase::addMenu(IUMenuBase* m, std::string name)
{
    m->name = name;
    addComponent(m);
}


