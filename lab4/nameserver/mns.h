#include "nameserverinterface.h"
#include <map>
#include <string>

using std::map;
using std::string;

class MNS: public NameServerInterface 
{
public:
    void insert(const HostName&, const IPAddress&);
    bool remove(const HostName&);
    IPAddress lookup(const HostName&) const;
private:
    map<const string,const unsigned int> data;
};