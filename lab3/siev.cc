#include <string>
#include "siev.h"
#include <vector>
#include <iostream>

using std::string;
using std::vector;

Siev::Siev(int size)
{
    data = string(size, 'P');
    data.replace(0, 2, "CC");
    for (int i = 0; i < size; i++)
    {
        if (data.at(i) == 'P')
        {
            for (int j = i + i; j < size; j = j + i)
            {
                data.replace(j, 1, "C");
            }
        }
    }
}

vector<int> Siev::getPrimes(int nbr)
{
    vector<int> ret;
    for (int i = 0; i < nbr; i++)
    {
        if(data.at(i) == 'P')
        {
            ret.push_back(i);
        }
    }
    return ret;
}

