//
//  IUBase.hpp
//  imgui-lib
//
//  Created by Alex on 09/07/2018.
//  Copyright © 2018 Alex Nadzharov. All rights reserved.
//

#ifndef IUBase_hpp
#define IUBase_hpp

#include <vector>

class IUWindowController;

class IUBase {
protected:
    IUWindowController* _windowController = 0;

    std::vector<IUBase*> _components;

    void addComponent(IUBase* c) { _components.push_back(c); }
    void removeComponent(IUBase* c) { _components.erase(std::remove(_components.begin(), _components.end(), c)); }
    void clearComponents() { _components.clear(); }

    void _drawComponents()
    {
        for (auto c : _components)
            c->draw();
    }
    void _shortcutComponents()
    {
        for (auto c : _components)
            c->shortcuts();
    }

public:
    virtual void draw() = 0;
    virtual void shortcuts() = 0;

    virtual void drawContents() = 0;

    virtual void setWindowController(IUWindowController* w)
    {
        _windowController = w;
    }
    IUWindowController* windowController() { return _windowController; }
};

// component type - T
template <typename T>
class IUBaseT : public IUBase {
protected:
    std::vector<T*> _components;

    void _drawComponents()
    {
        for (auto c : _components)
            c->draw();
    }
    void _shortcutComponents()
    {
        for (auto c : _components)
            c->shortcuts();
    }

    void _setWindowControllerComponents()
    {
        for (auto c : _components)
            c->_windowController = _windowController;
    }

public:
    void addComponent(T* c)
    {
        c->_windowController = _windowController;
        _components.push_back(c);
    }
    void removeComponent(T* c) { _components.erase(std::remove(_components.begin(), _components.end(), c)); }
    void clearComponents() { _components.clear(); }

    virtual void setWindowController(IUWindowController* w) override
    {
        IUBase::setWindowController(w);
        _setWindowControllerComponents();
    }

    virtual void draw() override
    {
        _drawComponents();
    };

    virtual void shortcuts() override
    {
        _shortcutComponents();
    }

    virtual void drawContents() override{};
};
#endif /* IUBase_hpp */
