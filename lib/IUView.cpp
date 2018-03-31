//
//  IIUView.cpp
//  imguiController
//
//  Created by Alex on 22/03/2018.
//

#include "IUView.hpp"

void IUView::addObserver(IUObserver* o)
{
    o->sender = this;
    _observers.push_back(o);
};
void IUView::removeObserver(IUObserver* o){};
void IUView::removeAllObservers()
{
    _observers.clear();
};

void IUView::addObserverFor(int k, IUObserver* o)
{
    o->sender = this;
    _keyedObservers[k].push_back(o);
};

void IUView::removeObserverFor(int k, IUObserver* o){};

void IUView::removeAllObserversFor(int k)
{
    _keyedObservers[k].clear();
};

//---

void IUView::updated()
{
    for (IUObserver* o : _observers)
    {
        o->sender = this;
        o->updated();
    }
}

void IUView::updated(int key)
{
    for (IUObserver* o : _keyedObservers[key])
    {
        o->sender = this;
        o->updated();
    }
}
