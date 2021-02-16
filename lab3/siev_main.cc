#include <string>
#include "siev.h"
#include <vector>
#include <iostream>

using std::string;
using std::vector;

int main()
{   
    Siev siev = Siev(99999);
    vector<int> primes = siev.getPrimes(99999);
    for(int i = 0; i < 201; i++)
    {
        std::cout << primes[i] << "\n";
    }
    
    std::cout << primes[primes.size() - 1] << "\n";
    return 0;
}
