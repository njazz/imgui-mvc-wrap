//

#include "IUAction.hpp"
#include "imgui.h"
#include <cctype>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>

#ifndef UIShortcut_hpp
#define UIShortcut_hpp

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

    // imgui-ready
    bool keyPressed();

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

    static IUKey Period() { return IUKey(".", { GLFW_KEY_PERIOD }); }
    static IUKey Comma() { return IUKey(",", { GLFW_KEY_COMMA }); }

    static IUKey Delete() {return IUKey("Del",{GLFW_KEY_DELETE});}
    static IUKey Backspace() {return IUKey("Del",{GLFW_KEY_BACKSPACE});}

    static IUKey Equal() {return IUKey("=",{GLFW_KEY_EQUAL});}
    static IUKey Minus() {return IUKey("-",{GLFW_KEY_MINUS});}

    static IUKey Up() {return IUKey("Up",{GLFW_KEY_UP});}
    static IUKey Down() {return IUKey("Down",{GLFW_KEY_DOWN});}
    static IUKey Left() {return IUKey("Left",{GLFW_KEY_LEFT});}
    static IUKey Right() {return IUKey("Right",{GLFW_KEY_RIGHT});}

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

    KEY_C(0);
    KEY_C(1);
    KEY_C(2);
    KEY_C(3);
    KEY_C(4);
    KEY_C(5);
    KEY_C(6);
    KEY_C(7);
    KEY_C(8);
    KEY_C(9);
};

//IUKey operator+(IUKey a, IUKey b);

class IUShortcut {
    std::vector<IUKey> _keys;

public:
    // imgui-ready
    bool keyPressed();

    explicit IUShortcut(IUKey k1);

    IUShortcut(IUKey k1, IUKey k2);

    explicit IUShortcut();

    void appendKey(IUKey k);

    static IUShortcut None();

    std::string str();
};

IUShortcut operator+(IUKey a, IUKey b);
IUShortcut operator+(IUShortcut a, IUKey b);

#endif
