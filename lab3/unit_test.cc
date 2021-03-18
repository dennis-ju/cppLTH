#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include "tag_remover.h"
#include "siev.h"
#include "date.h"
#include <vector>
#include <sstream>
#include <stdexcept>

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

template <class T>
std::string toString(T t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}

void TEST_A3()
{
    std::stringstream ss;
    std::stringstream check;
    Date date = Date();
    ss << "1-1-1";
    ss >> date;
    check << date;
    assert(check.str() == "0001-01-01");
}

void TEST_A4()
{
    double d = 1.234;
    Date date = Date(1, 1, 1);
    std::string sd = toString(d);
    std::string st = toString(date);
    assert(sd == "1.234");
    assert(st == "0001-01-01");
}

template <class T>
T string_cast(string s)
{
    std::stringstream ss{s};
    T t = T();
    ss >> t;
    if(ss.fail() || !ss.eof()) {
        throw std::invalid_argument("Invalid syntax.");
    }
    return t;
}

void TEST_A5()
{
    int i{0};
    double d{0};
    Date date;
    bool error = false;
    try
    {
        i = string_cast<int>("123");
        d = string_cast<double>("12.34");
        date = string_cast<Date>("2015-01-10");
        Date d_error = string_cast<Date>("ahds");
    }
    catch (std::invalid_argument &e)
    {
        error = true;
    }

        assert(i == 123);
        assert(d == 12.34);
        assert(date.getYear() == 2015);
        assert(error);
}

int main()
{
    TEST_A1();
    TEST_A2();
    TEST_A3();
    TEST_A4();
    TEST_A5();
    return 0;
}