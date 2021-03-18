#include "nameserverinterface.h"
#include <vector>
#include <string>

using std::vector;
using std::string;
using entry = std::pair<HostName, IPAddress>;

class HNS: public NameServerInterface 
{
public:
    HNS(size_t);
    void insert(const HostName&, const IPAddress&);
    bool remove(const HostName&);
    IPAddress lookup(const HostName&) const;
    int hash(string) const;
private:
    size_t size;
    vector<std::vector<entry>> data;
};