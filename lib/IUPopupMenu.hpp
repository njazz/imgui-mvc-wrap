//

#include "IUAction.hpp"
#include "imgui.h"
#include <cctype>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>

#ifndef IUPopupMenu_hpp
#define IUPopupMenu_hpp

//#include "glfw3.h"

#include "IUShortcut.hpp"

#include "IUWindowController.hpp"

#include "IUMenuBase.hpp"

class IUPopupMenu : public IUMenuBase {
public:
    virtual void draw() override;

    void openPopup();
};

#endif
