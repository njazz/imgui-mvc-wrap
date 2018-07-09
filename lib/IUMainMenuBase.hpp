//
#include "IUMenuBase.hpp"
#include <vector>

#ifndef UIMainMenuBase_hpp
#define UIMainMenuBase_hpp

#include "IUBase.hpp"

class IUMainMenuBase : public IUBaseT<IUMenuBase> {
//    std::vector<IUMenuBase*> _menus;

public:
    virtual void draw() override;
    //virtual void shortcuts() override{};

    void addMenu(IUMenuBase* m, std::string name = "");
};

#endif
