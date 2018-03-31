//
//  IUViewController.hpp
//  imguiController
//
//  Created by Alex on 22/03/2018.
//

#ifndef IUViewController_hpp
#define IUViewController_hpp

#include <stdio.h>
#include <vector>

class IUWindowController;

#include "IUView.hpp"

class IUViewController : public IUView {
    friend class IUWindowController;

public:
    virtual void setWindowController(IUWindowController* w) override;

    virtual void showViewController(){};
    virtual void hideViewController(){};
};
#endif /* IUViewController_hpp */
