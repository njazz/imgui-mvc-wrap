//
//  IIUView.cpp
//  imguiController
//
//  Created by Alex on 22/03/2018.
//

#include "IUView.hpp"

//void IUView::addObserver(IUAction* o)
//{
//    o->sender = this;
//    _observers.push_back(o);
//};
//void IUView::removeObserver(IUAction* o){};
//void IUView::removeAllObservers()
//{
//    _observers.clear();
//};

void IUView::addAction(int k, IUAction* o)
{
    o->sender = this;
    _keyedObservers[k].push_back(o);
};

void IUView::removeAction(int k, IUAction* o)
{
    auto it = std::find(_keyedObservers[k].begin(), _keyedObservers[k].end(), o);
    if (it != _keyedObservers[k].end())
        _keyedObservers[k].erase(it);
};

void IUView::removeAllActions(int k)
{
    _keyedObservers[k].clear();
};

//---

//void IUView::updated()
//{
//    for (IUAction* o : _observers) {
//        o->sender = this;
//        o->updated();
//    }
//}

void IUView::updated(int key)
{
    for (IUAction* o : _keyedObservers[key]) {
        o->sender = this;
        o->action();
    }
}
