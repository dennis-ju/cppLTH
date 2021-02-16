#ifndef SIEV_H
#define SIEV_H

#include <string>
#include <vector>

class Siev
{
    public:
        Siev(int);
        std::vector<int> getPrimes(int);
    private:
        std::string data;
};

#endif