//
//  IUObserver.cpp
//  imguiController
//
//  Created by Alex on 22/03/2018.
//

#include "IUAction.hpp"

IUAction::IUAction(std::function<void(void)> fn)
{
    _callback = fn;
}

void IUAction::action()
{
    if (_callback)
        _callback();
};

void IUAction::setCallback(std::function<void ()> fn)
{
    _callback = fn;
}
