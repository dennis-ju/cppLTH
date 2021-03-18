#include "vns.h"
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using std::pair;
using std::string;
using std::vector;

void VNS::insert(const HostName &name, const IPAddress &ip)
{
    data.push_back(std::make_pair(name, ip));
}
bool VNS::remove(const HostName &name)
{
    auto find = [&name](const entry &p) { return p.first == name; };
    auto i = std::find_if(data.begin(), data.end(), find);
    if (i != data.end())
    {
        data.erase(i);
        return true;
    }
    else
    {
        return false;
    }
}
IPAddress VNS::lookup(const HostName &name) const
{
    auto find = [&name](const entry &p) { return p.first == name; };
    auto i = std::find_if(data.begin(), data.end(), find);
    if (i != data.end())
    {
        return i->second;
    }
    else
    {
        return NON_EXISTING_ADDRESS;
    }
}