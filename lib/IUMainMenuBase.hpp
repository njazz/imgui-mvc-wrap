//
#include "IUMenuBase.hpp"
#include <vector>

#ifndef UIMainMenuBase_hpp
#define UIMainMenuBase_hpp

class IUMainMenuBase{
    std::vector <IUMenuBase*> _menus;

    IUWindowController* _windowController;
public:
    virtual void draw()
    {
        ImGui::BeginMainMenuBar();

        for (auto s: _menus)
            s->menu();

        ImGui::EndMainMenuBar();
    }

    void addMenu(IUMenuBase* m, std::string name = "")
    {
        m->name = name;
        m->windowController = _windowController;
        _menus.push_back(m);
    }

    void setWindowController(IUWindowController*w){
        _windowController = w;
        for (auto m : _menus)
            m->windowController = _windowController;
                                                  }

};

#endif
