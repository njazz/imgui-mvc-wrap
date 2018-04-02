//

#include "IUObserver.hpp"
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
    bool keyPressed();

    IUShortcut(IUKey k1);

    IUShortcut(IUKey k1, IUKey k2);

    explicit IUShortcut();

    void appendKey(IUKey k);

    static IUShortcut None();

    std::string str();
};

IUShortcut operator+(IUKey a, IUKey b);
IUShortcut operator+(IUShortcut a, IUKey b);

#endif
