//
//  DemoView.cpp
//  imguiController
//
//  Created by Alex on 22/03/2018.
//

#include "WidgetTestView.hpp"

float _setter(void *f, int idx)
{
    WidgetTestView::_array[idx] = ((float*)f)[idx];
    return 0.33;
};

float WidgetTestView::_array[16];
