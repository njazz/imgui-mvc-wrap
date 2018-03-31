//
//  TrackSeqView.hpp
//  nseq
//
//  Created by Alex on 22/03/2018.
//  Copyright © 2018 Alex Nadzharov. All rights reserved.
//

#ifndef TrackSeqView_hpp
#define TrackSeqView_hpp

#include <stdio.h>

#include "IUView.hpp"
#include "imgui.h"

class TrackSeqView : public IUView {
public:
    virtual void draw() override
    {
        //        ImGui::Begin("track");

        ImGui::Columns(2);

        ImGui::Text("tracks\n\n\n");

        ImGui::NextColumn();

        ImGui::Text("timeline");

        //        ImGui::End();
    };
};
#endif /* TrackSeqView_hpp */
