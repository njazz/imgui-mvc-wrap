//

#include "IUMenuBase.hpp"

IUKey operator+(IUKey a, IUKey b)
{
    return IUKey(a.str() + " + " + b.str(), a.key() | b.key());
}
