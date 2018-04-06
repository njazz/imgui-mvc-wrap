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

class IUWindowController;

class IUView : public IULayer {

//    std::vector<IUAction*> _observers;
    std::map<int, std::vector<IUAction*> > _keyedObservers;

//protected:
    float x;
    float y;
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
    
    void setX(float x_){x = x_;}
    void setY(float y_){y = y_;}
    float& getX(){return x;}
    float& getY(){return y;}
};

#endif /* IUView_hpp */
