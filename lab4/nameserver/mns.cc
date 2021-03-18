#include "mns.h"
#include <string>
#include <utility>
#include <map>

using std::map;
using std::pair;
using std::string;

void MNS::insert(const HostName &name, const IPAddress &ip)
{
    data.insert(make_pair(name, ip));
}

bool MNS::remove(const HostName &name)
{
    return data.erase(name);
}

IPAddress MNS::lookup(const HostName &name) const
{
    auto ret = data.find(name);
    if (ret != data.end())
    {
        return ret->second;
    } else {
        return NON_EXISTING_ADDRESS;
    }
}