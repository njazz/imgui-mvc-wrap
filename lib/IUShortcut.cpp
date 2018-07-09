//

#include "IUShortcut.hpp"

IUShortcut operator+(IUKey a, IUKey b)
{
    return (IUShortcut(a, b));
}

IUShortcut operator+(IUShortcut a, IUKey b)
{
    IUShortcut ret = IUShortcut(a);
    ret.appendKey(b);
    return ret;
}

// ---------------

bool IUKey::keyPressed()
{
    for (auto k : _keyCodes) {
        if //(ImGui::GetIO().KeysDown[k])//
            (ImGui::IsKeyDown(k))
        {
            //printf("key %s / %i\n",str().c_str(), k);
            return true;
        }
    }
    return false;
}

// ---------------

bool IUShortcut::keyPressed()
{
    bool ret = true;

    //printf("key count %i\n", (int)_keys.size());
    
    for (auto k : _keys) {
        printf("key %s pressed %i\n", k.str().c_str(), k.keyPressed());
        ret = ret && k.keyPressed();
    }
    
    if (ret) printf("ret\n");

    if (ret)
    //        for (int i = 0; i < 512; i++)
    //            ImGui::GetIO().KeysDown[i] = false;
        
    {
        for (auto k : _keys)
            for (auto kc : k.keyCodes())
                ImGui::GetIO().KeysDown[kc] = false;
    }

    //ImGui::GetIO().ClearInputCharacters();
    
    return ret;
}

IUShortcut::IUShortcut(IUKey k1)
{
    _keys.push_back(k1);
}

IUShortcut::IUShortcut(IUKey k1, IUKey k2)
{
    _keys.push_back(k1);
    _keys.push_back(k2);
}

IUShortcut::IUShortcut(){};

void IUShortcut::appendKey(IUKey k)
{
    _keys.push_back(k);
}

IUShortcut IUShortcut::None() { return IUShortcut(IUKey::None()); }

std::string IUShortcut::str()
{
    if (!_keys.size())
        return "";

    std::string ret = _keys[0].str();

    for (int i = 1; i < _keys.size(); i++)
        ret += " + " + _keys[i].str();

    return ret;
}
