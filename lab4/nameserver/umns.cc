#include "umns.h"
#include <string>
#include <utility>
#include <unordered_map>

using std::unordered_map;
using std::pair;
using std::string;

void UMNS::insert(const HostName &name, const IPAddress &ip)
{
    data.insert(make_pair(name, ip));
}

bool UMNS::remove(const HostName &name)
{
    return data.erase(name);
}

IPAddress UMNS::lookup(const HostName &name) const
{
    auto ret = data.find(name);
    if (ret != data.end())
    {
        return ret->second;
    } else {
        return NON_EXISTING_ADDRESS;
    }
}