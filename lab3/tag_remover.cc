#include "tag_remover.h"
#include <fstream>
#include <iostream>

using std::string;

TagRemover::TagRemover(std::ifstream &in) : data{""} 
{
    string line;
    while (std::getline(in, line))
    {
        data = data + line + "\n";
    }

    int i1 = data.find("<");
    int i2;
    while(i1 != string::npos)
    {
        i2 = data.find(">");
        data.erase(i1,i2-i1 + 1);
        i1 = data.find("<");
    }

    i1 = data.find("&");
    while(i1 != string::npos)
    {
        i2 = data.find(";", i1);
        change_special(i1, i2);
        i1 = data.find("&",i1 + 1);
    }
    
}

void TagRemover::change_special(int i1, int i2)
{
    string type = data.substr(i1, i2 - i1);

    if (type == "&gt")
        data.replace(i1, i2 - i1, ">");

    if (type == "&lt")
        data.replace(i1, i2 - i1, "<");

    if (type == "&nbsp")
        data.replace(i1, i2 - i1, " ");

    if (type == "&amp")
        data.replace(i1, i2 - i1, "&");        
}

string TagRemover::print()
{
    return data;   
}

