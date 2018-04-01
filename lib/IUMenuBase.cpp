//

#include "IUMenuBase.hpp"


//IUKey operator+(IUKey a, IUKey b)
//{
//    // TODO:
//    std::vector<int> retVector;
//    for (auto o: a.keyCodes())
//        retVector.push_back(o);
//    for (auto o: b.keyCodes())
//        retVector.push_back(o);

//    return IUKey(a.str() + " + " + b.str(), retVector);
//}

IUShortcut operator+(IUKey a, IUKey b)
{
    return (IUShortcut(a,b));
}

IUShortcut operator+(IUShortcut a, IUKey b)
{
    IUShortcut ret = IUShortcut(a);
    ret.appendKey(b);
    return ret;
}
