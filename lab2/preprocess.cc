#include <iostream>
#include <fstream>
#include <string>

std::string get_trigram(const std::string s)
{
    int size = s.size();
    std::string ret{s + " " + std::to_string(size - 2)};
    int i;
    for(i = 0; i < size-2; i++)
    {
        ret = ret + " " + s.substr(i,3);
    }
    return ret;
}

std::string to_lower(std::string s)
{
    int size = s.size();
    std::string ret{""};
    for(int i = 0; i < size; i++)
    {     
        char c = tolower(s.at(i));
        ret = ret + c;
    }
    return ret;
}

int main()
{
    std::ifstream infile("wordlist");
    std::ofstream outfile("words.txt");

    std::string s;
    while(std::getline(infile, s))
    {
        outfile << get_trigram(to_lower(s)) << '\n';
    }
    infile.close();
    outfile.close();
}