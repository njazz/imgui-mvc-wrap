//
//  IUObserver.hpp
//  imguiController
//
//  Created by Alex on 22/03/2018.
//

#ifndef IUObserver_hpp
#define IUObserver_hpp

#include <stdio.h>
#include <functional>

class IUView;

class IUObserver {
    std::function<void(void)> _callback = 0;

public:
    explicit IUObserver(std::function<void(void)> fn);

    // remove later?
    IUObserver(){};
    void setCallback(std::function<void(void)> fn);

    void updated();

    void operator()(){updated();}
    
    void* userObject = 0;
    IUView* sender = 0;
};

#endif /* IUObserver_hpp */
