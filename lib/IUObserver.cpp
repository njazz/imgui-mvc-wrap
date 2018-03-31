//
//  IUObserver.cpp
//  imguiController
//
//  Created by Alex on 22/03/2018.
//

#include "IUObserver.hpp"

IUObserver::IUObserver(std::function<void(void)> fn)
{
    _callback = fn;
}

void IUObserver::updated()
{
    if (_callback)
        _callback();
};

void IUObserver::setCallback(std::function<void ()> fn)
{
    _callback = fn;
}
