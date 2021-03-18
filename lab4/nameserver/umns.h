#include "nameserverinterface.h"
#include <unordered_map>
#include <string>

using std::unordered_map;
using std::string;

class UMNS: public NameServerInterface 
{
public:
    void insert(const HostName&, const IPAddress&);
    bool remove(const HostName&);
    IPAddress lookup(const HostName&) const;
private:
    unordered_map<HostName, IPAddress> data;
};