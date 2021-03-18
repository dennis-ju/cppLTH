#include <string>
#include "toString.h"
#include <sstream>

template <class T>
std::string toString(T t) 
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}