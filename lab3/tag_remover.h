#ifndef TAG_H
#define TAG_H

#include <string>
#include <fstream>

class TagRemover 
{
public:
    TagRemover(std::ifstream&);
    std::string print();
    void change_special(int, int);
private:
    std::string data;
};


#endif