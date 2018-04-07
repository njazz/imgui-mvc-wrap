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

#include <string>

class IUWindowController;
class IUMenuBase;

// imgui "child frame"
class IUView : public IULayer {

    std::map<int, std::vector<IUAction*> > _actions;

public:
    IUView()
    {
        idString = "V" + std::to_string((long)this);
    }

    IUMenuBase* contextMenu = 0;

    float alpha = 0.75;

    void addAction(int k, IUAction* o);
    void removeAction(int k, IUAction* o);
    void removeAllActions(int k);

    //---

    void updated(int key);

    void removeFromParentView();

    virtual void draw() override;
};

#endif /* IUView_hpp */
