//
//  NodeView.hpp
//  imguiController
//
//  Created by Alex on 22/03/2018.
//

#ifndef NodeView_hpp
#define NodeView_hpp

#include <stdio.h>
#include "IUView.hpp"
#include "imgui.h"
#include "imgui_node_graph_test.h"

class NodeView:public IUView{
public:
    virtual void draw() override{
        bool o;
        ShowExampleAppCustomNodeGraph(&o);
    }
};
#endif /* NodeView_hpp */
