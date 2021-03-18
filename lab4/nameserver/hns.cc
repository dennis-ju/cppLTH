#include "hns.h"
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using std::pair;
using std::string;
using std::vector;

HNS::HNS(size_t s) : data(vector<vector<entry>>(s)), size(s) {}

void HNS::insert(const HostName &name, const IPAddress &ip)
{
    unsigned long int index = hash(name);
    data[index].push_back(std::make_pair(name, ip));
}

bool HNS::remove(const HostName &name)
{
    vector<entry> *v = &data[hash(name)];
    auto find = [&name](const entry &p) { return p.first == name;};
    auto i = std::find_if(v->begin(), v->end(), find);
    if (i != v->end())
    {
        v->erase(i);
        return true;
    }
    else
    {
        return false;
    }
}
IPAddress HNS::lookup(const HostName &name) const
{
    const vector<entry> &v = data[hash(name)];
    auto find = [&name](const entry &p) { return p.first == name;};
    auto i = std::find_if(v.begin(), v.end(), find);
    if (i != v.end())
    {
        return i->second;
    }
    else
    {
        return NON_EXISTING_ADDRESS;
    }
}

int HNS::hash(string s) const
{
   int seed = 243; 
   unsigned long hash = 0;
   for(int i = 0; i < s.length(); i++)
   {
      hash = (hash * seed) + s[i];
   }
   return hash % size;
}