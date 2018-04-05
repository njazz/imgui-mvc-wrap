//
//  IUAction.hpp
//  imguiController
//
//  Created by Alex on 22/03/2018.
//

#ifndef IUObserver_hpp
#define IUObserver_hpp

#include <stdio.h>
#include <functional>

class IUView;

class IUAction {
    std::function<void(void)> _callback = 0;

public:
    explicit IUAction(std::function<void(void)> fn);

    // remove later?
    IUAction(){};
    void setCallback(std::function<void(void)> fn);

    void action();

    void operator()(){action();}
    
    void* userObject = 0;
    IUView* sender = 0;
};

#endif /* IUObserver_hpp */
