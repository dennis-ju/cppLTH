#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include "tag_remover.h"
#include "siev.h"
#include <vector>

using std::string;
using std::vector;

void TEST_A1()
{
    std::ifstream in{"test.html"};
    std::ifstream no_tag{"test_no_tag.html"};
    TagRemover tr = TagRemover(in); // read from in

    string line;
    string expect = "";
    while (std::getline(no_tag, line))
    {
        expect = expect + line + "\n";
    }
    assert(tr.print() == expect); 
    
}

void TEST_A2()
{
    Siev siev = Siev(99999);
    vector<int> primes = siev.getPrimes(99999);
    assert(primes[199] == 1223);
}

int main()
{
    TEST_A1();
    TEST_A2();
    return 0;
}