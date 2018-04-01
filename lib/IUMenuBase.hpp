//

#include "IUObserver.hpp"
#include "imgui.h"
#include <cctype>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>

#ifndef UIMenuBase_hpp
#define UIMenuBase_hpp

#include "IUWindowController.hpp"

#include "glfw3.h"

//
#define KEY_C(x) \
    static IUKey Key##x() { return IUKey(#x, { GLFW_KEY_##x }); };

//
class IUKey {
    std::string _string;
    std::vector<int> _keyCodes = { 0 };

public:
    IUKey(std::string s, std::vector<int> keyCodes)
        : _string(s)
        , _keyCodes(keyCodes){

        };

    std::string str() { return _string; }
    std::vector<int> keyCodes() { return _keyCodes; }

    // unused
    bool compareWith(int key)
    {
        for (auto k : _keyCodes) {
            if (k == key)
                return true;
        }
        return false;
    }

    // imgui-ready
    bool keyPressed()
    {
        for (auto k : _keyCodes) {
            if (ImGui::IsKeyDown(k))
                return true;
        }
        return false;
    }

    static IUKey None() { return IUKey("", { 0 }); }
    static IUKey Ctrl() { return IUKey("Ctrl", { GLFW_KEY_LEFT_CONTROL, GLFW_KEY_RIGHT_CONTROL }); }
    static IUKey Action()
    {
        // osx
        return IUKey("Cmd", { GLFW_KEY_LEFT_SUPER, GLFW_KEY_LEFT_SUPER });
        // else
        // return IUKey("Ctrl", 0);
    }
    static IUKey Shift() { return IUKey("Shift", { GLFW_KEY_LEFT_SHIFT, GLFW_KEY_RIGHT_SHIFT }); }
    static IUKey Alt() { return IUKey("Alt", { GLFW_KEY_LEFT_ALT, GLFW_KEY_RIGHT_ALT }); }

    static IUKey Slash() { return IUKey("/", { GLFW_KEY_SLASH }); }

    static IUKey Dot() { return IUKey(".", { GLFW_KEY_PERIOD }); }

    KEY_C(A);
    KEY_C(B);
    KEY_C(C);
    KEY_C(D);
    KEY_C(E);
    KEY_C(F);
    KEY_C(G);
    KEY_C(H);
    KEY_C(I);
    KEY_C(J);
    KEY_C(K);
    KEY_C(L);
    KEY_C(M);
    KEY_C(N);
    KEY_C(O);
    KEY_C(P);
    KEY_C(Q);
    KEY_C(R);
    KEY_C(S);
    KEY_C(T);
    KEY_C(U);
    KEY_C(V);
    KEY_C(W);
    KEY_C(X);
    KEY_C(Y);
    KEY_C(Z);
};

//IUKey operator+(IUKey a, IUKey b);

class IUShortcut {
    std::vector<IUKey> _keys;

public:
    // imgui-ready
    bool keyPressed()
    {
        bool ret = true;

        for (auto k : _keys) {
            ret = k.keyPressed();

            //            if (ret) {
            //                printf("shortcut %s key pressed: %s [%i]\n", str().c_str(), k.str().c_str(), ret);
            //                printf("%i[%i] %i[%i]\n", _keys[0].keyCodes()[0], _keys[0].keyPressed(), _keys[1].keyCodes()[0], _keys[1].keyPressed());
            //            }
        }

        //        if (ret)
        //            printf("shortcut %s >>>", str().c_str());

        return ret;
    }

    IUShortcut(IUKey k1)
    {
        _keys.push_back(k1);
    }

    IUShortcut(IUKey k1, IUKey k2)
    {
        _keys.push_back(k1);
        _keys.push_back(k2);
    }

    IUShortcut(){};

    void appendKey(IUKey k)
    {
        _keys.push_back(k);
    }

    static IUShortcut None() { return IUShortcut(IUKey::None()); }

    std::string str()
    {
        if (!_keys.size())
            return "";

        std::string ret = _keys[0].str();

        for (int i = 1; i < _keys.size(); i++)
            ret += " + " + _keys[i].str();

        return ret;
    }
};

IUShortcut operator+(IUKey a, IUKey b);
IUShortcut operator+(IUShortcut a, IUKey b);

class IUMenuBase {
    std::map<int, IUObserver*> _actions;
    std::map<int, IUShortcut*> _shortcuts;

public:
    std::string name;

    IUWindowController* windowController = 0;

    void shortcuts()
    {

        for (auto k : _shortcuts) {
            if (k.second)
                if (k.second->keyPressed())
                    _itemAction(k.first);
        }
    }

    void item(std::string name, int action = 0, IUShortcut shortcut = IUShortcut::None(), bool checked = false, bool enabled = true)
    {
        //_shortcuts[action] = &shortcut;
        if (shortcut.keyPressed())
            _itemAction(action);

        if (ImGui::MenuItem(name.c_str(), shortcut.str().c_str(), checked, enabled)) {

            _itemAction(action);
        }
    }

    void _itemAction(int action)
    {
        if (action) {
            if (_actions[action]) {
                _actions[action]->updated();
                if (windowController)
                    windowController->restoreContext();
            }
        }
    }

    virtual void draw(){};

    void menu()
    {

        if (ImGui::BeginMenu(name.c_str())) {
            draw();
            ImGui::EndMenu();
        }

        shortcuts();
    }

    void setAction(int key, IUObserver* a) { _actions[key] = a; };
};

#endif
