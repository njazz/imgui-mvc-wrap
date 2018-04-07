//
//  IUView.hpp
//  imguiController
//
//  Created by Alex on 22/03/2018.
//

#ifndef IUView_hpp
#define IUView_hpp

#include <map>
#include <stdio.h>
#include <vector>

#include "IUAction.hpp"

#include "IULayer.hpp"

#include "imgui.h"

class IUWindowController;

class IUView : public IULayer {

    //    std::vector<IUAction*> _observers;
    std::map<int, std::vector<IUAction*> > _keyedObservers;

    float _cx = 0;
    float _cy = 0;

public:
    void addAction(int k, IUAction* o);
    void removeAction(int k, IUAction* o);
    void removeAllActions(int k);

    //---

    void updated(int key);

    void removeFromParentView()
    {
        if (_parent)
            _parent->removeSubview(this);
    }

    void setX(float x) {_x = x;
                       // if (_parent) _x += _parent->x();
                       }
    void setY(float y) { _y = y;
                         //if (_parent) _y += _parent->y();
                       }

    float& getX()
    {
        _cx = _x + offset.x;
        if (_parent) _cx += _parent->x();
        return _cx ;
    }
    float& getY()
    {
        _cy = _y + offset.y;
        if (_parent) _cy += _parent->y();
        return _cy;
    }
    
    
};

#endif /* IUView_hpp */
