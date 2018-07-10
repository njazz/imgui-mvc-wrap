//
//  IUBase.hpp
//  imgui-lib
//
//  Created by Alex on 09/07/2018.
//  Copyright © 2018 Alex Nadzharov. All rights reserved.
//

#ifndef IUBase_hpp
#define IUBase_hpp

#include <functional>
#include <vector>

class IUWindowController;

class IUBase {
protected:
    IUWindowController* _windowController = 0;

    //    std::vector<IUBase*> _components;

    //    void addComponent(IUBase* c) {
    //        if (!c) return;
    //        _components.push_back(c); }
    //    void removeComponent(IUBase* c) {
    //        if (!c) return;
    //        _components.erase(std::remove(_components.begin(), _components.end(), c)); }
    //    void clearComponents() { _components.clear(); }

    //    void _drawComponents()
    //    {
    //        for (auto c : _components)
    //            c->draw();
    //    }
    //    void _shortcutComponents()
    //    {
    //        for (auto c : _components)
    //            c->shortcuts();
    //    }

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
private:
    // bool _componentsLock = false;
    std::vector<std::function<void(void)> > _componentUpdateQueue = {};

protected:
    std::vector<T*> _components;

    void _drawComponents()
    {
        for (auto c : _components)
            c->draw();

        _updateComponents();
    }
    void _shortcutComponents()
    {
        for (auto c : _components)
            c->shortcuts();
    }

    void _updateComponents()
    {
        for (auto q : _componentUpdateQueue)
            (q)();
        _componentUpdateQueue.clear();
    }

    void _setWindowControllerComponents()
    {
        for (auto c : _components)
            c->_windowController = _windowController;
    }

public:
    void addComponent(T* c)
    {
        if (!c)
            return;

        _componentUpdateQueue.push_back([&,c]() {

            c->_windowController = _windowController;
            _components.push_back(c);

        });
        
        _updateComponents();
    }
    void removeComponent(T* c)
    {
        if (!c)
            return;
        _componentUpdateQueue.push_back([&,c]() {

            _components.erase(std::remove(_components.begin(), _components.end(), c));

        });
        
        _updateComponents();
    }
    void clearComponents()
    {

        _componentUpdateQueue.push_back([&]() {

            _components.clear();

        });
        
        _updateComponents();
    }

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
