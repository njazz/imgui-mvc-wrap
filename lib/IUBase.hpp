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

#include <algorithm>

class IUWindowController;

// abstract base
class IUBase {
protected:
    IUWindowController* _windowController = 0;

    virtual void _drawContents() = 0;
    virtual void _shortcutContents() = 0;

    void _acceptKeyboard();
    void _acceptMouse();
public:
    virtual void draw() = 0;

    virtual void setWindowController(IUWindowController* w);
    IUWindowController* windowController();
};

// component type - T
template <typename T>
class IUBaseT : public IUBase {
private:
    std::vector<std::function<void(void)> > _componentUpdateQueue = {};

protected:
    std::vector<T*> _components;

    void _drawComponents();
    void _shortcutComponents();

    void _updateComponents();

    void _setWindowControllerComponents();

    virtual void _drawContents() override{};
    virtual void _shortcutContents() override{};

public:
    void addComponent(T* c);
    void removeComponent(T* c);
    void clearComponents();

    virtual void setWindowController(IUWindowController* w) override;

    virtual void draw() override;
    //    virtual void shortcuts() override;
};

// ---------- template ----------

template <typename T>
void IUBaseT<T>::_drawComponents()
{
    for (auto c : _components)
        c->draw();

    _updateComponents();
}

template <typename T>
void IUBaseT<T>::_shortcutComponents()
{
    for (auto c : _components)
        c->_shortcutContents();
}

template <typename T>
void IUBaseT<T>::_updateComponents()
{
    for (auto q : _componentUpdateQueue)
        (q)();
    _componentUpdateQueue.clear();
}

template <typename T>
void IUBaseT<T>::_setWindowControllerComponents()
{
    for (auto c : _components)
        c->_windowController = _windowController;
}

template <typename T>
void IUBaseT<T>::addComponent(T* c)
{
    if (!c)
        return;

    _componentUpdateQueue.push_back([&, c]() {

        c->_windowController = _windowController;
        _components.push_back(c);

    });

//    _updateComponents();
}

template <typename T>
void IUBaseT<T>::removeComponent(T* c)
{
    if (!c)
        return;
    _componentUpdateQueue.push_back([&, c]() {

        _components.erase(std::remove(_components.begin(), _components.end(), c));

    });

//    _updateComponents();
}

template <typename T>
void IUBaseT<T>::clearComponents()
{

    _componentUpdateQueue.push_back([&]() {

        _components.clear();

    });

//    _updateComponents();
}

template <typename T>
void IUBaseT<T>::setWindowController(IUWindowController* w)
{
    IUBase::setWindowController(w);
    _setWindowControllerComponents();
}

template <typename T>
void IUBaseT<T>::draw()
{
    _drawContents();
    _drawComponents();
    _shortcutContents();
    _shortcutComponents();
};

//template <typename T>
//void IUBaseT<T>::shortcuts()
//{
//    _shortcutComponents();
//}

#endif /* IUBase_hpp */
