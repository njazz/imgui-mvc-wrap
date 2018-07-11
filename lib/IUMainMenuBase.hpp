//
#include "IUMenuBase.hpp"
#include <vector>

#ifndef UIMainMenuBase_hpp
#define UIMainMenuBase_hpp

#include "IUBase.hpp"

class IUMainMenuBase : public IUBaseT<IUMenuBase> {

public:
    virtual void draw() override;

    void addMenu(IUMenuBase* m, std::string name = "");
};


class IUMenuBarBase : public IUBaseT<IUMenuBase> {

public:
    virtual void draw() override;

    void addMenu(IUMenuBase* m, std::string name = "");
};

#endif
