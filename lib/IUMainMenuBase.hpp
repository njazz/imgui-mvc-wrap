//
#include "IUMenuBase.hpp"
#include <vector>

#ifndef UIMainMenuBase_hpp
#define UIMainMenuBase_hpp

class IUMainMenuBase {
    std::vector<IUMenuBase*> _menus;

    IUWindowController* _windowController = 0;

public:
    virtual void draw();

    void addMenu(IUMenuBase* m, std::string name = "");
    void setWindowController(IUWindowController* w);
};

#endif
