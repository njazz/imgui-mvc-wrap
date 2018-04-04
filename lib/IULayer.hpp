//
//  IULayer.hpp
//  nseq
//
//  Created by Alex on 28/03/2018.
//  Copyright © 2018 Alex Nadzharov. All rights reserved.
//

#ifndef IULayer_hpp
#define IULayer_hpp

#include <stdio.h>

#include <vector>

class IUWindowController;

class IULayer {
protected:
    std::vector<IULayer*> _subviews;
    void _drawSubviews();

    IULayer* _parent = 0;
    IUWindowController* _windowController = 0;

public:
    virtual void draw();

    void addSubview(IULayer* v);
    void removeSubview(IULayer* v)
    {
        _subviews.erase(std::remove(_subviews.begin(), _subviews.end(), v), _subviews.end());
    }
    void removeAllSubviews();

    virtual void setWindowController(IUWindowController* w);
    IUWindowController* windowController();

    float x;
    float y;
    float width;
    float height;

    bool hidden = false;
};

#endif /* IULayer_hpp */
