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

#include "IUObserver.hpp"

#include "IULayer.hpp"

class IUWindowController;

class IUView : public IULayer {

//    std::vector<IUObserver*> _observers;
    std::map<int, std::vector<IUObserver*> > _keyedObservers;

protected:
public:
//    void addObserver(IUObserver* o);
//    void removeObserver(IUObserver* o);
//    void removeAllObservers();

    void addObserverFor(int k, IUObserver* o);
    void removeObserverFor(int k, IUObserver* o);
    void removeAllObserversFor(int k);

    //---

//    void updated();
    void updated(int key);


    void removeFromParentView()
    {
        if (_parent)
            _parent->removeSubview(this);
    }
};

#endif /* IUView_hpp */
